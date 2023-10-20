#include <stdio.h>

int main()
{
    int a, b, c, d, max_value, position = 1, ret = -1;

    do
    {
        printf("Podaj 4 liczby: ");
        ret = scanf("%d %d %d %d", &a, &b, &c, &d);
        if (ret != 4)
        {
            printf("Blad wczytywania danych!\n");
        }
        while (getchar() != '\n')
            ;
    } while (ret != 4);

    max_value = a;
    if (b > max_value)
    {
        max_value = b;
        position = 2;
    }
    if (c > max_value)
    {
        max_value = c;
        position = 3;
    }
    if (d > max_value)
    {
        max_value = d;
        position = 4;
    }

    printf("Najwieksza liczba to %d, zostala podana jako %d\n", max_value, position);
    return 0;
}