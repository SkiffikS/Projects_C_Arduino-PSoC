#include <stdio.h>

int k;
int MyArray[6] = {0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0x00};
int MyArrayResults[6];

int main()
{
    for(int i = 0; i < 6; i++)
    {
        MyArrayResults[i] = MyArray[i] & 0x3F;
        MyArrayResults[i] = MyArrayResults[i] | 0x03;
        printf("MyArrayResults[%d] = %d;\n", i, MyArrayResults[i]);
    }
}
