#include <stdio.h>
#include <math.h>
#pragma warning(disable : 4996)

void wczytaj_dane(double *p, double *k, double *dx);
double fun(double x);

int main()
{
    double i, poczatek, koniec, skok;
    wczytaj_dane(&poczatek, &koniec, &skok);
    for (i = poczatek; i <= koniec; i = i + skok)
    {
        printf("dla x = %lf f(x) = %lf\n", i, fun(i));
    }
    return 0;
}

void wczytaj_dane(double *p, double *k, double *dx)
{
    int ret = -1;
    do
    {
        printf("Podaj początek, koniec oraz kroki: ");
        ret = scanf("%lf %lf %lf", p, k, dx);
        if (ret != 3)
        {
            printf("Blad wczytywania danych!\n");
        }
        else if (*p > *k)
        {
            printf("Początek nie moze byc wiekszy od konca\n");
        }
        while (getchar() != '\n')
            ;
    } while (ret != 3 || *p > *k);
}

double fun(double x)
{
    return 1 / (x * x + sqrtf(1 + 2 * x + 3 * x * x));
}