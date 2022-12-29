#include "project.h"

char s; // вибір сигналу
int i = 0; //вибір семплу

uint8 NumOfSamplesInPeriod_1 = 20;
uint8 NumOfSamplesInPeriod_2 = 40;

        const uint8 Samples_1[] = 
        { // масив семплів 1-го сигналу
            128, 167, 203, 231, 249,
            255, 249, 231, 230, 167,
            128, 89, 53, 25, 7,
            1, 7, 25, 53, 89
        };

        const uint8 Samples_2[] = 
        { // масив семплів 2-го сигналу
            127, 158, 185, 205, 215,
            217, 211, 200, 189, 181,
            178, 181, 189, 200, 211,
            217, 215, 205, 185, 158,
            127, 96, 69, 49, 39,
            37, 43, 54, 65, 73,
            76, 73, 65, 54, 43,
            37, 39, 49, 69, 96 
        };

        CY_ISR(Signal_1)
        { // підпрограмма виведення сигналу
            IDAC_SetValue(Samples_1[i]); // виведення з перетворювача семплів
            if(i == NumOfSamplesInPeriod_1)
            {
                i = 0;
            } // повернення семпла
            i++; // інкремент для семплування
        }
        
       CY_ISR(Signal_2)
       { // підпрограмма виведення сигналу
            IDAC_SetValue(Samples_2[i]); // виведення з перетворювача семплів
            if(i == NumOfSamplesInPeriod_2)
            {
                i = 0;
            } // повернення семпла
            i++; // інкремент для семплування
       }

int main(void)
{
    CyGlobalIntEnable;
    
    UART_Start(); // запуск UART    
    IDAC_Start(); // запуск перетворювача

    switch(s)
    {
        case 1:
            
            UART_UartPutString("Start:Signal_1"); // Виведення рядка
            Timer_Signal_1_Start(); // Запуск таймера
            ISR_Signal_1_StartEx(Signal_1); // Запуск підпрограми
            break; // Вихід з case 1
            
        case 2:
            
            UART_UartPutString("Start:Signal_2"); // Виведення рядка
            Timer_Signal_2_Start(); // Запуск таймера
            ISR_Signal_2_StartEx(Signal_2); // Запуск підпрограми
            break; // Вихід з case 2
    }
    
    for(;;){}
}



