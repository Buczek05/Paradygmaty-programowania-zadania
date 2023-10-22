#include <stdio.h>

void zamien(int *, int *);

int main()
{
    int x = 1, y = 11;
    zamien(&x, &y);
    printf("x = %d, y = %d", x, y);
    return 0;
}

void zamien(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}