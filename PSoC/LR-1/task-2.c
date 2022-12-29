#include <stdio.h>

int main()
{
    int n = 12343;
    int k = 0;
    int t = n;
    int d;
    int result = 0;
    while(t > 0)
    {
        d = t % 10;
        if (d == 3)
        {
            k++;
        }
        t /= 10;
    }
    result = k;
    printf("result = %d\n", result);
    return 0;
}
