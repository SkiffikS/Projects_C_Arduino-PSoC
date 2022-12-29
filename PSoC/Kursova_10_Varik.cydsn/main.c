#include "project.h"
/* Кількість каналів */
#define NUMBER_OF_CHANNELS (3)
/* Аргумент Pin_Write API, щоб увімкнути світлодіод */
#define LED_ON_VALUE (0)
/* Аргумент API Pin_Write для вимкнення світлодіода */
#define LED_OFF_VALUE (1)
/* Розмір буфера UART */
#define UART_BUFFER_SIZE (10)
/* Індекси буфера UART */
#define UART_BUFFER_A_IDX (0)
#define UART_BUFFER_T_IDX (1)
#define UART_BUFFER_PLUS_IDX (2) // PLUS - Символ "+"
#define UART_BUFFER_CHANNEL_IDX (3)
#define UART_BUFFER_D_VALUE_IDX (5)
#define UART_BUFFER_H_VALUE_IDX (7)
#define UART_BUFFER_L_VALUE_IDX (9)
/* Зсув ASCII для цифр. Код ASCII 0 у таблиці ASCII. */
#define ASCII_OFFSET_FOR_DIGITS (48)
/* Тип дескриптора каналу */
typedef struct
{
    uint8 Current_D; /* Лічильник тривалості стану D */
    uint8 Current_H; /* Лічильник тривалості стану H */
    uint8 Current_L; /* Лічильник тривалості стану L */
    uint8 Max_D; /* Максимальна тривалість стану D */
    uint8 Max_H; /* Максимальна тривалість стану H */
    uint8 Max_L; /* Максимальна тривалість стану L */
    void (*PinControlFunction)(uint8); /* Функція керування вказівником на контакт */
} ChannelDescriptorType;

/* Масив дескрипторів каналів із розміром номера каналу */
ChannelDescriptorType ChannelDescriptorsArray[NUMBER_OF_CHANNELS];
/* Буфер для зберігання даних з UART */
char UartBuffer[UART_BUFFER_SIZE];
/* Індекс поточного елемента буфера UART */
uint8 UartBufferIdx;

/* Функція яка сповіщає що була введена неправильна команда */
void Error_Return(void)
{
    UART_1_UartPutChar('\n');
    UART_1_UartPutChar('\r');
    UART_1_UartPutChar(' ');
    UART_1_UartPutChar('E');
    UART_1_UartPutChar('r');
    UART_1_UartPutChar('r');
    UART_1_UartPutChar('o');
    UART_1_UartPutChar('r');
    UART_1_UartPutChar(' ');
    UART_1_UartPutChar('\n');
    UART_1_UartPutChar('\r');
}

/**************************************************************************
Функція контролю каналу
Він зменшує лічильники D, H або L і перемикає стан контакту, коли потрібно.
**************************************************************************/
void ChannelController(uint8 Channel_Number)
{
    if(ChannelDescriptorsArray[Channel_Number].Current_D > 0)
    {
        ChannelDescriptorsArray[Channel_Number].Current_D--;
        ChannelDescriptorsArray[Channel_Number].PinControlFunction(LED_OFF_VALUE);
        return;
    }
    
    if(ChannelDescriptorsArray[Channel_Number].Current_H > 0)
    {
        ChannelDescriptorsArray[Channel_Number].Current_H--;
        ChannelDescriptorsArray[Channel_Number].PinControlFunction(LED_ON_VALUE);
        return;
    }
    
    if(ChannelDescriptorsArray[Channel_Number].Current_L > 0)
    {
        ChannelDescriptorsArray[Channel_Number].Current_L--;
        ChannelDescriptorsArray[Channel_Number].PinControlFunction(LED_OFF_VALUE);
        return;
    }
    
    if(ChannelDescriptorsArray[Channel_Number].Current_D == 0 && ChannelDescriptorsArray[Channel_Number].Current_H == 0 && ChannelDescriptorsArray[Channel_Number].Current_L == 0)
    {
        ChannelDescriptorsArray[Channel_Number].Current_D = 
        ChannelDescriptorsArray[Channel_Number].Max_D;
        
        ChannelDescriptorsArray[Channel_Number].Current_H = 
        ChannelDescriptorsArray[Channel_Number].Max_H;
        
        ChannelDescriptorsArray[Channel_Number].Current_L = 
        ChannelDescriptorsArray[Channel_Number].Max_L;

        return;
    }
}
/**************************************************************************
Обробник переривань викликається кожні 500ms
**************************************************************************/
CY_ISR(TimeSlotInterrupt)
{
    uint8 CurrentChannelNumber;
    /* Виклик функції контролера каналу для кожного каналу */
    for (CurrentChannelNumber = 0; CurrentChannelNumber < NUMBER_OF_CHANNELS; CurrentChannelNumber++)
    {
       ChannelController(CurrentChannelNumber);
    }
}
/**************************************************************************
Ця функція для оновлення дескрипторів каналів і стану PIN-коду.
Лічильники D, H і L всіх інших каналів скидаються в початковий стан
щоб запустити всі канали синхронно.
Параметри:
ChannelNumber - канал для оновлення;
D - нове значення затримки D;
H - нове значення тривалості імпульсу H;
L - нове значення тривалості паузи L;
**************************************************************************/
void UpdateChannelDescriptor(uint8 ChannelNumber, uint8 D, uint8 H, uint8 L)
{
    uint8 ChannelIdx;

    /* Увійдіть у критичний розділ, щоб уникнути переривань під час оновлення дескрипторів каналу */
    CyGlobalIntDisable; /* Вимкнути глобальні переривання. */
    /* Оновити значення дескриптора каналу з даних, отриманих від UART */
    ChannelDescriptorsArray[ChannelNumber].Max_D = D;
    ChannelDescriptorsArray[ChannelNumber].Max_H = H; 
    ChannelDescriptorsArray[ChannelNumber].Max_L = L; 

    /* Перезавантажте лічильники в усіх каналах, щоб синхронізувати всі канали. */
    for (ChannelIdx = 0; ChannelIdx < NUMBER_OF_CHANNELS; ChannelIdx++)
    {
        ChannelDescriptorsArray[ChannelIdx].Current_D = ChannelDescriptorsArray[ChannelIdx].Max_D;
        ChannelDescriptorsArray[ChannelIdx].Current_H = ChannelDescriptorsArray[ChannelIdx].Max_H;
        ChannelDescriptorsArray[ChannelIdx].Current_L = ChannelDescriptorsArray[ChannelIdx].Max_L;
        /* Скинути вихідний контакт, що відповідає цьому каналу */
        ChannelDescriptorsArray[ChannelIdx].PinControlFunction(LED_OFF_VALUE);
    }
    /* Вийти з критичного розділу */
    CyGlobalIntEnable; /* Увімкнути глобальні переривання. */
}
/**************************************************************************
Ця функція аналізує буфер UART і оновлює лічильники D, H і L
**************************************************************************/
void UartBufferParser(void)
{
    uint8 ChannelNumber;
    uint8 ValueD, ValueH, ValueL;
     
    ValueD = UartBuffer[UART_BUFFER_D_VALUE_IDX] - ASCII_OFFSET_FOR_DIGITS;
    ValueH = UartBuffer[UART_BUFFER_H_VALUE_IDX] - ASCII_OFFSET_FOR_DIGITS;
    ValueL = UartBuffer[UART_BUFFER_L_VALUE_IDX] - ASCII_OFFSET_FOR_DIGITS;   
    ChannelNumber = UartBuffer[UART_BUFFER_CHANNEL_IDX] - ASCII_OFFSET_FOR_DIGITS;

    if ('A' != UartBuffer[UART_BUFFER_A_IDX])
    {
        /* Вміст буфера UART не відповідає очікуваному значенню "A". Повернення. */
        Error_Return();
        return;
    }
    if ('T' != UartBuffer[UART_BUFFER_T_IDX])
    {
        Error_Return();
        return;
    }
    for(uint8 idx = UART_BUFFER_PLUS_IDX; idx < 9;)
    {
        if ('+' != UartBuffer[idx])
        {
            Error_Return();
            return;
        }
        else
        {
            idx = idx + 2;
        }
    }

    if (ValueD >= 0 && ValueD <= 9 && ValueH >= 0 && ValueH <= 9 && ValueL >= 0 && ValueL <= 9 && ChannelNumber >= 0 && ChannelNumber < NUMBER_OF_CHANNELS)
    {
        /* Оновити дескриптор каналу отриманими значеннями D, H і L */
        UpdateChannelDescriptor(ChannelNumber, ValueD, ValueH, ValueL);
    }
    else
    {
        Error_Return();
    }
}
/**************************************************************************
Ця функція для читання байтів (символів) з UART, збору даних до
 буфер і розібрати буфер.
**************************************************************************/
void UartDataReader(void)
{
     char CurrentCharacter = 0;
     CurrentCharacter = UART_1_UartGetChar();
     if (0 == CurrentCharacter)
     {
         /* Якщо поточний символ дорівнює нулю, це означає, що дані не отримані від UART. Повернення з функції. */
         return;
     }
     
     /* Надішліть отриманий символ, щоб побачити його в терміналі */
     UART_1_UartPutChar(CurrentCharacter);
     
     /* Перевірте, чи отриманий символ є "A" (== індикатор початку пакета) */
     if ('A' == CurrentCharacter)
     {
         /* UART отримав символ «А». Скинути індекс на початок буфера UART */
         UartBufferIdx = 0;
     }
     /* Помістити отриманий символ у буфер UART і збільшити індекс. */
     UartBuffer[UartBufferIdx] = CurrentCharacter;
     UartBufferIdx++;
     
     /* Перевірте, чи заповнений буфер UART */
     if (UART_BUFFER_SIZE == UartBufferIdx)
     {
         /* Буфер UART заповнений. Почніть розбирати цей буфер. */
         UartBufferParser();
         /* Скинути індекс на початок буфера UART */
         UartBufferIdx = 0;
     }
}
/**************************************************************************
Ця функція виконує загальну ініціалізацію.
**************************************************************************/
void Init(void)
{
     /* Призначте функції керування контактами для дескрипторів каналів. */
     ChannelDescriptorsArray[0].PinControlFunction = Blue_Output_Write;
     ChannelDescriptorsArray[1].PinControlFunction = Red_Output_Write;
     ChannelDescriptorsArray[2].PinControlFunction = Green_Output_Write;
    /* Запуск компонента UART */
     UART_1_Start();

     /* Запустити компонент переривання */
     isr_1_StartEx(TimeSlotInterrupt);

     /* Запуск таймера */
     Timer_1_Start();
}
/**************************************************************************
Основна функція
**************************************************************************/
int main(void)
{
     CyGlobalIntEnable; /* Увімкнути глобальні переривання. */
     Blue_Output_Write(1);
     Red_Output_Write(1);
     Green_Output_Write(1);
     /* Виконайте загальну ініціалізацію */
     Init(); 
     /* Безкінечний цикл */
     for(;;)
     {
        UartDataReader();
     }
}


