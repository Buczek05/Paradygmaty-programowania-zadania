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
    char *d[MAX_LINES], bufor[MAX_LINE], find_text[MAX_LINE], *t;
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
        len = strlen(bufor)+1;
        if (!(d[i] = (char*)malloc((unsigned)len)))
        {
            printf("Brak pamieci\n");
            exit(3);
        }
        strcpy(d[i], bufor);
        i++;
    }
    d[i] = (char *)0;

    printf("Podaj tekst: ");
    t = fgets(find_text, MAX_LINE, stdin);

    find_text[strlen(find_text) - 1] = '\0'; // usuwanie znaku nowej linii

    for (int i =0; i < MAX_LINES && d[i] != (char *)0; i++)
    {
        char *w_text = d[i], *w_find_text = find_text;
        while (*w_text && *w_find_text)
        {
            if (*w_text != *w_find_text) break;
            w_text++;
            w_find_text++;
        }
        if (!*w_find_text)
        {
            printf("%s", d[i]);
        }
    }
}