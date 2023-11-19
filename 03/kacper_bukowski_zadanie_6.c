#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 256
int main() {
/*Ile razy litera a powtarza sie w tekscie*/
    char d[MAX_LINE], *dd;
    int l;
    l = 0;
    dd = fgets(d, MAX_LINE, stdin);
    while (*dd != '\0')
    {
        if (*dd == 'a') l++;
        dd++;
    }
    printf("%s\n%d\n", d, l);
}