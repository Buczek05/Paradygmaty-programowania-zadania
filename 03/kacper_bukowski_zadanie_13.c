#include <stdio.h>
#define MAX_LINE 256
int main()
{
    char d[MAX_LINE], *dd, b, z;
    int l = 0;
    printf("Podaj tekst:\n");
    dd = fgets(d, MAX_LINE, stdin);
    printf("Podaj znak:\n");
    z = getchar();
    while ((b = *dd) != '\0')
    {
        if (b==z) printf(" pozycja znaku %c w tekscie %d\n", z, l);
        l++;
        dd++;
    }
}