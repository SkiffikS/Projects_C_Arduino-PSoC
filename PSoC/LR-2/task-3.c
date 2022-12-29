#include <stdio.h>


int main()
{
    float numbers_1[5] = {11.2, 15.1, 62.3, 1.1, 9.1};
    float numbers_2[5] = {3.1, 99.2, 163.1, 12.1, 2.0};
    float result[5];
    for(int i = 0; i < 5; i ++)
    {
        result[i] = numbers_1[i] / numbers_2[i];
        printf("%.2f = %.2f / %.2f;\n", result[i], numbers_1[i], numbers_2[i]);
    }
    
    return 0;
}