#include <stdio.h>
#include <stdint-gcc.h>

int FindDecimicalNumbers(uint32_t MyBcdNumber, uint8_t Number);
uint8_t DecimalNumbers[4];

int main()
{
    uint8_t DecimalNumbers_0 = FindDecimicalNumbers(0x7843, 0);
    uint8_t DecimalNumbers_1 = FindDecimicalNumbers(0x7843, 1);
    uint8_t DecimalNumbers_2 = FindDecimicalNumbers(0x7843, 2);
    uint8_t DecimalNumbers_3 = FindDecimicalNumbers(0x7843, 3);
    
    printf("DecimalNumbers_0 = %d;\n", DecimalNumbers_0);
    printf("DecimalNumbers_1 = %d;\n", DecimalNumbers_1);
    printf("DecimalNumbers_2 = %d;\n", DecimalNumbers_2);
    printf("DecimalNumbers_3 = %d;\n", DecimalNumbers_3);
}

int FindDecimicalNumbers(uint32_t MyBcdNumber, uint8_t Number)
{
    uint8_t DecimalNumbers[4];
    if(Number == 0){DecimalNumbers[0] = (MyBcdNumber & 0x000F);}
    if(Number == 1){DecimalNumbers[1] = (MyBcdNumber & 0xF000) >> 4;}
    if(Number == 2){DecimalNumbers[2] = (MyBcdNumber & 0xF000) >> 8;}
    if(Number == 3){DecimalNumbers[3] = (MyBcdNumber & 0xF000) >> 12;}
}