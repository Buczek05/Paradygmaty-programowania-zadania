//Instrukcje switch, case, break, continue
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 256
int main()
{
/* Liczba wystąpień liter a, b oraz liter od b do y */
    char d[MAX_LINE], *dd, b;
    int l, k, m;
    l = k = m = 0;
    dd = fgets(d, MAX_LINE, stdin);
    while (b = *dd++, b != '\0')
    {
        if (!(b >= 'a' && b <= 'y')) continue;
        switch (b)
        {
            case 'a':
                l++;
                break;
            case 'b':
                k++;
            default:
                m++;
        }
    }
    printf("%d %d %d\n", l, k, m);
}