#include <stdio.h>
#pragma warning(disable : 4996)

int wez_liczbe();
int silnia(int n);

int main()
{
    int n = wez_liczbe();
    printf("Silnia %d wynosi %d", n, silnia(n));
    return 0;
}

int wez_liczbe()
{
    int liczba, ret = -1;
    do
    {
        printf("Podaj silnie: ");
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

int silnia(int n)
{
    int wynik = 1;
    for (int i = 1; i <= n; i++)
    {
        wynik *= i;
    }
    return wynik;
}