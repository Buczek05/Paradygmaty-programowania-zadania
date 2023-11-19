#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 256
#define MAX_LINES 200
FILE *fd;
int main()
{
/* Ile slow w ielu liniach tekstu */
    char *d[MAX_LINES], bufor[MAX_LINE], *linia_moment;
    int len, i, l;
    if (!(fd = fopen("03/dane.txt", "r")))
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
    d[i] = (char *)0;
    int linia1, linia2;
    printf("Podaj linie 1: ");
    scanf("%d", &linia1);
    printf("Podaj linie 2: ");
    scanf("%d", &linia2);

    linia_moment = d[linia1];
    d[linia1] = d[linia2];
    d[linia2] = linia_moment;
    i = 0;
    while (i < MAX_LINES && d[i] != (char *)0)
    {
        printf("%s\n", d[i]);
        i++;
    }
}