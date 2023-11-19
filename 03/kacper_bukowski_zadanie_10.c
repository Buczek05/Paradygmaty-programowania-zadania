#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 256
int main()
{
    char d[MAX_LINE], *dd, p = ' ', b;
    int l = 0;
    dd = fgets(d, MAX_LINE, stdin);
    printf("%s\n", dd);
/* Tu zostanie wyprowadzony cały wczytany tekst */
    while ((b = *dd) != '\0')
    {
        if (b != ' ')
            if (p == ' ') l++;
        p = b;
        dd++;
    }
    printf("%d\n", l);
/* A tu zostanie wyprowadzony pusty tekst */
    printf("%s\n", dd);
}