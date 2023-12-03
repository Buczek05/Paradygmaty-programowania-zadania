#include <stdio.h>
double fun1();
static int fun2();
extern int fun3();
static int c = 5;
double a, b = 10;
char *xx[] = { "mama","tato","stryjek",(char *)0};
double aa[] = { 1,2,3,4,5,6 };
int main()
{
    double x, y = 5;
    int i, j, k;
    static double aa[] = { 11,12,13,14,15,16 };
    printf("%lf %lf \n", aa[0], aa[1]);
    j = fun2();
    k = fun3();
    printf("j=%d, k= %d\n", j, k);
}
double fun1(int x, int y)
{
    static char *xx[] = { "pies","kot","mysz",(char *)0 };
    int i = 0;
    i++;
}
char *xxxx[] = { "zima","wiosna","lato",(char *)0 };
static int fun2()
{
    static int k = 0;
    puts("ppp fun2");
    k++;
    return(k);
}