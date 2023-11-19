#include <stdio.h>

int main()
{
    /* Kody ASCII */
    int i = 0;
/* int i=' '; jest poprawne */
    while (++i < 256)
    {
        printf("%3d %c ", i, i);
        if (!((i - 32) % 4)) printf("\n");
    }
    printf("\n");
}