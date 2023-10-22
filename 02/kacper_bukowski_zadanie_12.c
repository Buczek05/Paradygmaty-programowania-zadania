#include <stdio.h>
#pragma warning(disable : 4996)

int wez_liczbe();
int sum_n_liczb(int n);

int main()
{
    int n;
    n = wez_liczbe();
    printf("Suma %d liczb wynosi %d", n, sum_n_liczb(n));
    return 0;
}

int wez_liczbe()
{
    int liczba, ret = -1;
    do
    {
        printf("Podaj liczbe naturalna: ");
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
int sum_n_liczb(int n)
{
    if (n > 0)
        return n + sum_n_liczb(n - 1);
    else
        return 0;
}