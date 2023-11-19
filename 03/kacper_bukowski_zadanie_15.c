#include <stdio.h>
#define MAX_LINE 256
int main()
{
    char d[MAX_LINE], *dd, stary_znak, nowy_znak;
    printf("Podaj tekst:\n");
    dd = fgets(d, MAX_LINE, stdin); // dd to adres pierwszego znaku w tablicy d
    printf("Podaj znak do zastąpienia:\n");
    stary_znak = getchar(); getchar();
    printf("Podaj nowy znak:\n");
    nowy_znak = getchar();
    while (*dd)
    {
        if (*dd==stary_znak) *dd = nowy_znak;
        dd++;
    }
    printf("%s\n", d);
}