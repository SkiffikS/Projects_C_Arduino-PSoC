#include <stdio.h>
#include <stdint-gcc.h>

int32_t lab4_ArraySum(uint8_t* arr, uint32_t size);
int32_t lab4_ArrayProd(uint8_t* arr, uint32_t size);

uint8_t testArray[5] = {2, 6, 12, 8, 3};

int main(void)
{
    printf("Array sim = %d;\n", lab4_ArraySum(testArray, 3));
    printf("Array prod = %d;\n", lab4_ArrayProd(testArray, 3));
}

int32_t lab4_ArraySum(uint8_t * arr, uint32_t size)
{
    uint32_t value = 0;
    uint32_t i;
    for(int i = 0; i < size; i++)
    {
        value += arr[i];
    }
    return value;
}

int32_t lab4_ArrayProd(uint8_t * arr, uint32_t size)
{
    uint32_t value = 1;
    uint32_t i;
    for(int i = 0; i < size; i++)
    {
        value *= arr[i];
    }
    return value;
}