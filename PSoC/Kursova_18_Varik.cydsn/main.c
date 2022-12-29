#include "project.h"
/* Number of channnels */
#define NUMBER_OF_CHANNELS (4)
/* The argument of the Pin_Write API to turn on the LED */
#define LED_ON_VALUE (0)
/* The argument of the Pin_Write API to turn off the LED */
#define LED_OFF_VALUE (1)
/* Size of UART buffer */
#define UART_BUFFER_SIZE (11)
/* UART buffer indeces */
#define UART_BUFFER_A_IDX (0)
#define UART_BUFFER_T_IDX (1)
#define UART_BUFFER_PLUS_FIRST_IDX (2) // PLUS - Symbol "+"
#define UART_BUFFER_C_IDX (3)
#define UART_BUFFER_CHANNEL_IDX (4)
#define UART_BUFFER_EQUALS_IDX (5) // EQUALS - Symbol "="
#define UART_BUFFER_D_VALUE_IDX (6)
#define UART_BUFFER_PLUS_SECOND_IDX (7) // PLUS - Symbol "+"
#define UART_BUFFER_H_VALUE_IDX (8)
#define UART_BUFFER_PLUS_THIRD_IDX (9) // PLUS - Symbol "+"
#define UART_BUFFER_L_VALUE_IDX (10)
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

/* Channels descriptors array with size of channels number */
ChannelDescriptorType ChannelDescriptorsArray[NUMBER_OF_CHANNELS];
/* Buffer to store data from UART */
char UartBuffer[UART_BUFFER_SIZE];
/* Index to the current UART buffer element */
uint8 UartBufferIdx;

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

/**************************************************************************
 This function perfoms channel control.
 It decrements counters D, H or L and toggles pin state when required.
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
/**************************************************************************
 Interrupt Handler called every 500ms
**************************************************************************/
CY_ISR(TimeSlotInterrupt)
{
 uint8 CurrentChannelNumber;
 /* Call Channel controller function for each of channel */
 for (CurrentChannelNumber = 0;
 CurrentChannelNumber < NUMBER_OF_CHANNELS;
 CurrentChannelNumber++)
 {
    ChannelController(CurrentChannelNumber);
 }
}
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
void UpdateChannelDescriptor(uint8 ChannelNumber, uint8 D, uint8 H, uint8 L)
{
 uint8 ChannelIdx;
 
 /* Enter critical section to avoid interrupts during channel descriptors update */
 CyGlobalIntDisable; /* Disable global interrupts. */
 /* Update channel descriptor values from the data received from UART */
 ChannelDescriptorsArray[ChannelNumber].Max_D = D;
 ChannelDescriptorsArray[ChannelNumber].Max_H = H; 
 ChannelDescriptorsArray[ChannelNumber].Max_L = L; 
 
 /* Reload counters in all channels to synchronize all channels. */
 for (ChannelIdx = 0; ChannelIdx < NUMBER_OF_CHANNELS; ChannelIdx++)
 {
 ChannelDescriptorsArray[ChannelIdx].Current_D = ChannelDescriptorsArray[ChannelIdx].Max_D;
 ChannelDescriptorsArray[ChannelIdx].Current_H = ChannelDescriptorsArray[ChannelIdx].Max_H;
 ChannelDescriptorsArray[ChannelIdx].Current_L = ChannelDescriptorsArray[ChannelIdx].Max_L;
 /* Reset output pin corresponding to this channel */
 ChannelDescriptorsArray[ChannelIdx].PinControlFunction(LED_OFF_VALUE);
 }
 /* Exit critical section */
 CyGlobalIntEnable; /* Enable global interrupts. */
}
/**************************************************************************
 This function parses the UART buffer and update counters D, H and L
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
    
 if (ValueD >= 0 && ValueD <= 9 &&
     ValueH >= 0 && ValueH <= 9 &&
     ValueL >= 0 && ValueL <= 9 &&
     ChannelNumber >= 0 && ChannelNumber < NUMBER_OF_CHANNELS)
    {
        /* Update channel descriptor with received values D, H and L */
        UpdateChannelDescriptor(ChannelNumber, ValueD, ValueH, ValueL);
    }
 else
    {
        Error_Return();
    }
}
/**************************************************************************
 This function to read bytes (characters) from UART, collect data to the
 buffer and parse the buffer.
**************************************************************************/
void UartDataReader(void)
{
 char CurrentCharacter = 0;
 CurrentCharacter = UART_1_UartGetChar();
 if (0 == CurrentCharacter)
 {
 /* If current character equal to zero it means that no data received
from UART.
 Retrun from the function. */
 return;
 }
 
 /* Send back received character to see it in the terminal */
 UART_1_UartPutChar(CurrentCharacter);
 
 /* Check if received character is "A" (== indicator of packet begin) */
 if ('A' == CurrentCharacter)
 {
 /* UART received character "A". Reset index to begin of the UART buffer
*/
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
 }
}
/**************************************************************************
 This function performs generic initialization.
**************************************************************************/
void Init(void)
{
 /* Assign pin control functions to the channel descriptors. */
 ChannelDescriptorsArray[0].PinControlFunction = Blue_Output_Write;
 ChannelDescriptorsArray[1].PinControlFunction = Green_Output_Write;
 ChannelDescriptorsArray[2].PinControlFunction = Red_Output_Write;
 ChannelDescriptorsArray[3].PinControlFunction = Blue_Output_Write;
 
/* UART component start */
 UART_1_Start();

 /* Start Interrupt component */
 isr_1_StartEx(TimeSlotInterrupt);

 /* Start component Timer */
 Timer_1_Start();
}
/**************************************************************************
 Main function
**************************************************************************/
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
