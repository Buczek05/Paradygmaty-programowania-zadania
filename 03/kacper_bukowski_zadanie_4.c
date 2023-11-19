#include <stdio.h>
#define MAX_LINE 256
int main()
{
    char d[MAX_LINE], b;
    int k, l;
    k = 0; l = 0;
    fgets(d, MAX_LINE, stdin);
    while ((b = d[k]) != '\0')
    {
        if (b == 'a') l++;
        k++;
    }
    printf("%s\n%d\n", d, l);
}