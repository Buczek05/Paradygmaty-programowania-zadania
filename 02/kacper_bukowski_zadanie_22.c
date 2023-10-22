#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
    int a = 0, b = 0, c = 0, inne = 0;
    char znak;
    while (1)
    {
        scanf("%c", &znak);
        while (getchar() != '\n')
            ;
        if (znak == 'a')
        {
            a++;
            continue;
        }
        if (znak == 'b')
        {
            b++;
            continue;
        }
        if (znak == 'c')
        {
            c++;
            continue;
        }
        if (znak == 'e')
            break;
        inne++;
    }
    printf("a = %d, b = %d, c = %d, inne = %d", a, b, c, inne);

    return 0;
}