#include <project.h>

uint16 c = 18;
uint16 i = 1;

CY_ISR(program)
{
    switch(i)
    {
        case 1:
        
            red_Write(0);
            if (c == 0)
            {
                c = 6;
                i = 2;
            }
            break;
           
        case 2:
            
            red_Write(0);
            green_Write(0); 
            if (c == 0)
            {
                c = 12;
                i = 3;
            }
            break;
           
        case 3:
            
            green_Write(0);
            if (c == 0)
            {
                c = 18;
                i = 1;
            }
            break;
    }
}

int main()
{
    CyGlobalIntEnable;
    ISR_StartEx(program);
    Timer_1_Start();
    green_Write(1);
    for(;;){}
}

