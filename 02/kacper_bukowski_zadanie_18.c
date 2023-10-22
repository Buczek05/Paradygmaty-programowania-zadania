#include <stdio.h>
#pragma warning(disable : 4996)

int wez_liczbe();

int main()
{
    int n;
    n = wez_liczbe();
    for (int i = 0; i < n; i++)
    {
        printf("Hello world!\n");
    }
    // lub
    // while (n--)
    // {
    //     printf("Hello world!\n");
    // }
    return 0;
}

int wez_liczbe()
{
    int liczba, ret = -1;
    do
    {
        printf("Podaj ile razy ma sie wydrukowac \" Hello World !\"");
        ret = scanf("%d", &liczba);
        if (ret != 1)
        {
            printf("Blad wczytywania danych!\n");
        }
        while (getchar() != '\n')
            ;
    } while (ret != 1);
    return liczba;
}