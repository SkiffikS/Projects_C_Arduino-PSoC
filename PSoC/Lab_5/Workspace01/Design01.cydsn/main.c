#include "project.h" 
 
int main(void) 
{ 
    CyGlobalIntEnable;
 
    Pin_1_Green_Write(1); 
    Pin_2_Red_Write(1); 
    Pin_3_Blue_Write(1); 
 
    for(;;) 
    {
        // variant 4
        // purple (5000)
        // yellow (3000)
        // white (1000)
         
        Pin_1_Green_Write(1);
        Pin_2_Red_Write(0);
        Pin_3_Blue_Write(0);
        // purple = red + blue
        
        Pin_1_Green_Write(0);
        Pin_2_Red_Write(0);
        Pin_3_Blue_Write(1);
        // yellow = red + green
        
        Pin_1_Green_Write(0); 
        Pin_2_Red_Write(0); 
        Pin_3_Blue_Write(0); 
        // white = red + green + blue
    } 
}