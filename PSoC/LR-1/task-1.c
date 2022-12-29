#include "math.h"
#include <stdio.h>

int i;
float d, j;

int main()
{
    d = 1;
    for(i = 1, j = 9; i <= 9; i++, j--)
    {
        d *= (i + cosf(j));
    }
    printf("result = %f", d);
    return 0;
}
