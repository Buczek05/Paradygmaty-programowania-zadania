#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 256
#define MAX_LINES 200
FILE *fd = NULL;
int ile(char *, int *, int *);
int main()
{
    char *d[MAX_LINES], bufor[MAX_LINE];
    int len, i, l, lm, ld;
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
        if ((d[i] = (char *)malloc((unsigned)len)) == (char*)NULL)
        {
            printf("Brak pamieci\n");
            exit(3);
        }
        strcpy(d[i], bufor);
        l += ile(d[i], &lm, &ld);
        printf("wiersz %d, lm=%d, ld=%d, l=%d\n", i, lm, ld, l);
        i++;
    }
    fclose(fd);
    fd = NULL;
    printf("%d\n", l);
}
int ile(char *te, int *lm, int *ld)
{
    int l = 0;
    *lm = *ld = 0;
    while (te++, *te){
        if (*te >= 97 && *te <= 122) (*lm)++;
        else if (*te >= 65 && *te <= 90) (*ld)++;
        else l++;
    }
    return l;
}