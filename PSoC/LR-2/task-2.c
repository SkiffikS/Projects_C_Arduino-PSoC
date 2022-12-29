#include <stdio.h>

typedef struct
{
    int day;
    int month;
    int year;
} birthay;

int main()
{
    birthay me;
    me.day = 10;
    me.month = 10;
    me.year = 2003;
    printf("My birthay:\n%d:%d:%d!", me.day, me.month, me.year);
    return 0;
}