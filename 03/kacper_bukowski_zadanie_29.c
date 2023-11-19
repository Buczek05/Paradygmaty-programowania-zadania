#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 256
#define MAX_LINES 200
FILE *fd;
int ile_slow(char *), licz_slowa(char **), licz_slowa_1(char **);
int main(int argc, char **argv)
{
/* Ile slow w ielu liniach tekstu */
    char *d[MAX_LINES], bufor[MAX_LINE];
    int len, i, l;
    if (argc != 2)
    {
        printf("Zła liczba argumentów\n");
        exit(1);
    }
    if (!(fd = fopen(argv[1], "r")))
    {
        printf("Blad otwarcia zbioru\n");
        exit(2);
    }
    i = 0;
    l = 0;
    while (i < MAX_LINES && fgets(bufor, MAX_LINE, fd))
    {
        len = strlen(bufor);
        bufor[len - 1] = '\0';
        if (!(d[i] = (char*)malloc((unsigned)len)))
        {
            printf("Brak pamieci\n");
            exit(3);
        }
        strcpy(d[i], bufor);
        i++;
    }
    d[i] = (char *)0; //znacznik końca tablicy wskaźników
    l = licz_slowa_1(d);
    printf("%d\n", l);
/* Tekst w pamieci, tablica d - wskazniki do linii tekstu */
}
int ile_slow(char *te)
{
    char p, b = ' ';
    int l = 0;
    while (p = b, b = *te++)
        if (b != ' ' && p == ' ') l++;
    return(l);
}
int licz_slowa_1(char *te[])
{
    int i, l = 0;
    i = 0;
    while (te[i] != (char *)0)
    {
        l += ile_slow(te[i]);
        i++;
    }
    return l;
}