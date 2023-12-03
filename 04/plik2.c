#include <stdio.h>
extern double fun1();
static double fun2();
int fun3();
static char *c[] = { "slon","lew","pantera",(char *)0 };
extern char *xx[];
static double fun2()
{
    static char *zz[] = { "krzeslo","szafa","tapczan",(char *)0 };
    puts("qqq fun2");
    return ((double) 2.0);
}
int fun3()
{
    double ff;
    puts("qqq fun3");
    ff = fun2();
    return (5);
}