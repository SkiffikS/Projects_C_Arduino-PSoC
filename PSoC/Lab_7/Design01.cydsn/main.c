#include "project.h"
uint8 s;
uint8 var1;
const uint8 Name[] = {"Chulup_Denis"}; // 12 submol

int main(void)
{
    UART_Start(); // запуск блоку UART
    UART_UartPutString("Start_program: ");

    CyGlobalIntEnable; 
    /*
    for(int i; i <= 12; i++)
    {
        UART_UartPutChar(Name[i]);
        CyDelay(1000);//1s
    }
    */
    
    s = UART_UartGetChar();
    // Зчитуємо з інтерфейсу UART символи
    
    if(s > 0u)
    {
        UART_UartPutChar(s);
        Green_Write(0);
        CyDelay(1000);//1s
        Green_Write(1);
    }
    else
    {
        Red_Write(0);
        CyDelay(1000);//1s
        Red_Write(1);
    }
}