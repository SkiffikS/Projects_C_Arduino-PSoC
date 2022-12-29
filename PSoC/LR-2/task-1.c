#include <stdio.h>

struct birthay
{
    int day;
    int month;
    int year;
};

int main()
{
    struct birthay me;
    me.day = 10;
    me.month = 10;
    me.year = 2003;
    printf("My birthay:\n%d:%d:%d!", me.day, me.month, me.year);
    return 0;
}
