#include "project.h"
/* Number of channnels */
#define NUMBER_OF_CHANNELS (3)
/* Variable to identify the first channel */
#define FIRST_CHANNEL (0)
/* Variable to identify the second channel */
#define SECOND_CHANNEL (1)
/* Variable to identify the third channel */
#define THIRD_CHANNEL (2)
/* The argument of the Pin_Write API to turn on the LED */
#define LED_ON_VALUE (0)
/* The argument of the Pin_Write API to turn off the LED */
#define LED_OFF_VALUE (1)
/* Size of UART buffer */
#define UART_BUFFER_SIZE (19)
/* UART buffer indexes */
#define UART_BUFFER_A_IDX (0)
#define UART_BUFFER_T_IDX (1)
#define UART_BUFFER_PLUS_FIRST_IDX (2) // PLUS - Symbol "+"
#define UART_BUFFER_C_IDX (3)
#define UART_BUFFER_O_IDX (4)
#define UART_BUFFER_N_IDX (5)
#define UART_BUFFER_F_IDX (6)
#define UART_BUFFER_EQUALS_IDX (7) // EQUALS - Symbol "="
/* Channel number one */
#define UART_BUFFER_D1_VALUE_IDX (8)
#define UART_BUFFER_H1_VALUE_IDX (9)
#define UART_BUFFER_L1_VALUE_IDX (10)
#define UART_BUFFER_PLUS_SECOND_IDX (11) // PLUS - Symbol "+"
/* Channel number two */
#define UART_BUFFER_D2_VALUE_IDX (12)
#define UART_BUFFER_H2_VALUE_IDX (13)
#define UART_BUFFER_L2_VALUE_IDX (14)
#define UART_BUFFER_PLUS_THIRD_IDX (15) // PLUS - Symbol "+"
/* Channel number three */
#define UART_BUFFER_D3_VALUE_IDX (16)
#define UART_BUFFER_H3_VALUE_IDX (17)
#define UART_BUFFER_L3_VALUE_IDX (18)
/* ASCII offset for digits. ASCII code of 0 in ASCII table. */
#define ASCII_OFFSET_FOR_DIGITS (48)
/* Channel Descriptor Type */
typedef struct
{
    uint8 Current_D; /* Counter of state D duration */
    uint8 Current_H; /* Counter of state H duration */
    uint8 Current_L; /* Counter of state L duration */
    uint8 Max_D; /* Maximum state D duration */
    uint8 Max_H; /* Maximum state H duration */
    uint8 Max_L; /* Maximum state L duration */
    void (*PinControlFunction)(uint8); /* Pointer to pin control function */
} ChannelDescriptorType;

// ==========================================================================================

/* Channels descriptors array with size of channels number */
ChannelDescriptorType ChannelDescriptorsArray[NUMBER_OF_CHANNELS];
/* Buffer to store data from UART */
char UartBuffer[UART_BUFFER_SIZE];

/* Index to the current UART buffer element */
uint8 UartBufferIdx;

// ==========================================================================================

/* This function notifies the user that an incorrect AT-command has been entered */
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
    
    if (     ChannelDescriptorsArray[Channel_Number].Current_D == 0 && 
             ChannelDescriptorsArray[Channel_Number].Current_H == 0 && 
             ChannelDescriptorsArray[Channel_Number].Current_L == 0)
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

// ==========================================================================================

/**************************************************************************
 Interrupt Handler called every 500ms
**************************************************************************/
CY_ISR(TimeSlotInterrupt)
{
    for(uint8 Number_Channel = 0; Number_Channel < NUMBER_OF_CHANNELS; Number_Channel++)
    {
        ChannelController(Number_Channel);
    }
}
// ==========================================================================================

/**************************************************************************
 This function to update channel descriptors and pin state.
 Counters D, H and L of all other channels are reset to the initial state
 to start all channels synchronously.
 Parameters:
 ChannelNumber - channel to be updated;
 D - new value of delay D;
 H - new value of pulse duration H;
 L - new value of pause duration L;
**************************************************************************/
void UpdateChannelDescriptor(uint8 D1, uint8 H1, uint8 L1, uint8 D2, uint8 H2, uint8 L2, uint8 D3, uint8 H3, uint8 L3)
{
 /* Enter critical section to avoid interrupts during channel descriptors update */
CyGlobalIntDisable; /* Disable global interrupts. */
 /* Update channel descriptor values from the data received from UART */
ChannelDescriptorsArray[FIRST_CHANNEL].Max_D = D1;
ChannelDescriptorsArray[FIRST_CHANNEL].Max_H = H1; 
ChannelDescriptorsArray[FIRST_CHANNEL].Max_L = L1;

ChannelDescriptorsArray[SECOND_CHANNEL].Max_D = D2;
ChannelDescriptorsArray[SECOND_CHANNEL].Max_H = H2; 
ChannelDescriptorsArray[SECOND_CHANNEL].Max_L = L2;

ChannelDescriptorsArray[THIRD_CHANNEL].Max_D = D3;
ChannelDescriptorsArray[THIRD_CHANNEL].Max_H = H3; 
ChannelDescriptorsArray[THIRD_CHANNEL].Max_L = L3;
 
// ********************** FIRST CHANNEL **********************
ChannelDescriptorsArray[FIRST_CHANNEL].Current_D = ChannelDescriptorsArray[FIRST_CHANNEL].Max_D;
ChannelDescriptorsArray[FIRST_CHANNEL].Current_H = ChannelDescriptorsArray[FIRST_CHANNEL].Max_H;
ChannelDescriptorsArray[FIRST_CHANNEL].Current_L = ChannelDescriptorsArray[FIRST_CHANNEL].Max_L;
 /* Reset output pin corresponding to this channel */
ChannelDescriptorsArray[FIRST_CHANNEL].PinControlFunction(LED_OFF_VALUE);
    
// ********************** SECOND CHANNEL **********************
ChannelDescriptorsArray[SECOND_CHANNEL].Current_D = ChannelDescriptorsArray[SECOND_CHANNEL].Max_D;
ChannelDescriptorsArray[SECOND_CHANNEL].Current_H = ChannelDescriptorsArray[SECOND_CHANNEL].Max_H;
ChannelDescriptorsArray[SECOND_CHANNEL].Current_L = ChannelDescriptorsArray[SECOND_CHANNEL].Max_L;
 /* Reset output pin corresponding to this channel */
ChannelDescriptorsArray[SECOND_CHANNEL].PinControlFunction(LED_OFF_VALUE);

// ********************** SECOND CHANNEL **********************
ChannelDescriptorsArray[THIRD_CHANNEL].Current_D = ChannelDescriptorsArray[THIRD_CHANNEL].Max_D;
ChannelDescriptorsArray[THIRD_CHANNEL].Current_H = ChannelDescriptorsArray[THIRD_CHANNEL].Max_H;
ChannelDescriptorsArray[THIRD_CHANNEL].Current_L = ChannelDescriptorsArray[THIRD_CHANNEL].Max_L;
 /* Reset output pin corresponding to this channel */
ChannelDescriptorsArray[THIRD_CHANNEL].PinControlFunction(LED_OFF_VALUE);

 /* Exit critical section */
CyGlobalIntEnable; /* Enable global interrupts. */
}

// ==========================================================================================

void UartBufferParser(void)
{
 uint8 ValueD1, ValueH1, ValueL1, ValueD2, ValueH2, ValueL2, ValueD3, ValueH3, ValueL3;
    
 ValueD1 = UartBuffer[UART_BUFFER_D1_VALUE_IDX] - ASCII_OFFSET_FOR_DIGITS;
 ValueH1 = UartBuffer[UART_BUFFER_H1_VALUE_IDX] - ASCII_OFFSET_FOR_DIGITS;
 ValueL1 = UartBuffer[UART_BUFFER_L1_VALUE_IDX] - ASCII_OFFSET_FOR_DIGITS;

 ValueD2 = UartBuffer[UART_BUFFER_D2_VALUE_IDX] - ASCII_OFFSET_FOR_DIGITS;
 ValueH2 = UartBuffer[UART_BUFFER_H2_VALUE_IDX] - ASCII_OFFSET_FOR_DIGITS;
 ValueL2 = UartBuffer[UART_BUFFER_L2_VALUE_IDX] - ASCII_OFFSET_FOR_DIGITS;

 ValueD3 = UartBuffer[UART_BUFFER_D3_VALUE_IDX] - ASCII_OFFSET_FOR_DIGITS;
 ValueH3 = UartBuffer[UART_BUFFER_H3_VALUE_IDX] - ASCII_OFFSET_FOR_DIGITS;
 ValueL3 = UartBuffer[UART_BUFFER_L3_VALUE_IDX] - ASCII_OFFSET_FOR_DIGITS;

 if ('A' != UartBuffer[UART_BUFFER_A_IDX])
    {
        /* UART buffer content does not match to the expected value "A". Return. */
        Error_Return();
        return;
    }
 if ('T' != UartBuffer[UART_BUFFER_T_IDX])
    {
        Error_Return();
        return;
    }
 if ('+' != UartBuffer[UART_BUFFER_PLUS_FIRST_IDX])
    {
        Error_Return();
        return;
    }
 
 if ('C' != UartBuffer[UART_BUFFER_C_IDX])
    {
        Error_Return();
        return;
    }
    
 if ('O' != UartBuffer[UART_BUFFER_O_IDX])
    {
        Error_Return();
        return;
    }
    
 if ('N' != UartBuffer[UART_BUFFER_N_IDX])
    {
        Error_Return();
        return;
    }
    
 if ('F' != UartBuffer[UART_BUFFER_F_IDX])
    {
        Error_Return();
        return;
    }
    
 if ('=' != UartBuffer[UART_BUFFER_EQUALS_IDX])
    {
        Error_Return();
        return;
    }
 
 if ('+' != UartBuffer[UART_BUFFER_PLUS_SECOND_IDX])
    {
        Error_Return();
        return;
    }
    
 if ('+' != UartBuffer[UART_BUFFER_PLUS_THIRD_IDX])
    {
        Error_Return();
        return;
    }
    
 if (ValueD1 >= 0 && ValueD1 <= 9 &&
     ValueH1 >= 0 && ValueH1 <= 9 &&
     ValueL1 >= 0 && ValueL1 <= 9 &&
     ValueD2 >= 0 && ValueD2 <= 9 &&
     ValueH2 >= 0 && ValueH2 <= 9 &&
     ValueL2 >= 0 && ValueL2 <= 9 &&
     ValueD3 >= 0 && ValueD3 <= 9 &&
     ValueH3 >= 0 && ValueH3 <= 9 &&
     ValueL3 >= 0 && ValueL3 <= 9)
    {
        /* Update channel descriptor with received values D, H and L */
        UpdateChannelDescriptor(ValueD1, ValueH1, ValueL1, ValueD2, ValueH2, ValueL2, ValueD3, ValueH3, ValueL3);
    }
 else
    {
        Error_Return();
    }
}
// ==========================================================================================

void UartDataReader(void)
{
 char CurrentCharacter = 0;
 CurrentCharacter = UART_1_UartGetChar();
 if (0 == CurrentCharacter)
 {
    /* If current character equal to zero it means that no data received from UART.
    Return from the function. */
    return;
 }
 
 /* Send back received character to see it in the terminal */
 UART_1_UartPutChar(CurrentCharacter);
 
 /* Check if received character is "A" (== indicator of packet begin) */
 if ('A' == CurrentCharacter)
 {
    /* UART received character "A". Reset index to begin of the UART buffer */
    UartBufferIdx = 0;
 }
 /* Put received character to UART buffer and increment index. */
 UartBuffer[UartBufferIdx] = CurrentCharacter;
 UartBufferIdx++;
 
 /* Check if UART buffer is filled */
 if (UART_BUFFER_SIZE == UartBufferIdx)
 {
    /* UART buffer is full. Start parse this buffer. */
    UartBufferParser();
    /* Reset index to begin of the UART buffer */
    UartBufferIdx = 0;
    UART_1_UartPutChar(' '); // To separate the input of AT-commands
 }
}

// ==========================================================================================

/**************************************************************************
 This function performs generic initialization.
**************************************************************************/
void Init(void)
{
 /* Assign pin control functions to the channel descriptors. */
 ChannelDescriptorsArray[0].PinControlFunction = Blue_Output_Write;
 ChannelDescriptorsArray[1].PinControlFunction = Green_Output_Write;
 ChannelDescriptorsArray[2].PinControlFunction = Red_Output_Write;

 /* UART component start */
 UART_1_Start();

 /* Start Interrupt component */
 isr_1_StartEx(TimeSlotInterrupt);

 /* Start component Timer */
 Timer_1_Start();
}

int main(void)
{
 CyGlobalIntEnable; /* Enable global interrupts. */
 Red_Output_Write(1);
 Blue_Output_Write(1);
 Green_Output_Write(1);
 /* Perform generic initialization */
 Init();

 /* Infinite loop */
 for(;;)
 {
    UartDataReader(); 
 }
}
/* [] END OF FILE */