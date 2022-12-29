#include <project.h>

uint16 t = 0;

CY_ISR(program_WORKER)
{
    LCD_Position(0, 1);
    t++;
    LCD_PrintInt16(t);
}

int main()
{
    CyGlobalIntEnable;
    ISR_StartEx(program_WORKER);
    Timer_1_Start();
    LCD_Init();
    for(;;){}
}
