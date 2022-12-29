#include <stdio.h>

struct CustomType
{
    int X[5];
    int Y[5];
};

struct CustomType S;

int main()
{
    int x_numbers = 10;
    int y_numbers = 0;
    printf("\nresult:\n\n");
    for(int i = 0; i < 5; i++)
    {
        S.X[i] = x_numbers;
        S.Y[i] = y_numbers;
        
        if(y_numbers == 4)
        {
            y_numbers += 2;
        }
        
        printf("S.X[%d] = %d;\tS.Y[%d] = %d;\n", i, x_numbers, i, y_numbers);
        
        x_numbers++;
        y_numbers += 2;
    }
}