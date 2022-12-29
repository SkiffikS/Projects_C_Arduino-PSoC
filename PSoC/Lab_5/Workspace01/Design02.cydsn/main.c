#include "project.h" 
 
 
int main(void) 
{ 
    CyGlobalIntEnable;
 
    Pin_Green_Write(1); // inactive
    for(;;)
    {
        Pin_Green_Write(Button_Read());
    }
}