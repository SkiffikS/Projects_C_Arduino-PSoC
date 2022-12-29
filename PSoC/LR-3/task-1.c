#include <stdio.h>

int main()
{
    unsigned char a = 52, b = 19, n = 2;
    printf("a = %d; b = %d; n = %d;\n\n", a, b, n);
    
    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);
    printf("~b = %d\n", ~b);
    printf("a << n = %d\n", a << n);
    printf("b >> n = %d\n", b >> n);
    
    printf("a = %d\n", a = a & 0xF0);
    printf("b = %d\n", b = b & 0xF0);
}