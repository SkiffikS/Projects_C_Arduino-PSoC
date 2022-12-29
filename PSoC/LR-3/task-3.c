#include <stdio.h>
#include <stdlib.h>

u_int32_t MyBcdNumber = 0x3579;
u_int8_t DecimalNumbers[4];

int main()
{
    DecimalNumbers[0] = (MyBcdNumber & 0xF000) >> 12;
    DecimalNumbers[1] = (MyBcdNumber & 0xF000) >> 8;
    DecimalNumbers[2] = (MyBcdNumber & 0xF000) >> 4;
    DecimalNumbers[3] = (MyBcdNumber & 0x000F);
    
    printf("DecimalNumbers[0] = %d;\n", DecimalNumbers[0]);
    printf("DecimalNumbers[1] = %d;\n", DecimalNumbers[1]);
    printf("DecimalNumbers[2] = %d;\n", DecimalNumbers[2]);
    printf("DecimalNumbers[3] = %d;\n", DecimalNumbers[3]);
}
