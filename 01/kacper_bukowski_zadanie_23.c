#include <stdio.h>
#include <math.h>
#pragma warning(disable : 4996)

typedef struct
{
    double a, b, c;
} Trojkat;

Trojkat wczytaj_trojkat();
int sprawdz_warunek_trojkata(Trojkat t);
double oblicz_polowe_obwodu(Trojkat t);
double oblicz_pole(Trojkat t, double polowa_obwodu);
double oblicz_promien_kola_wpisanego(double pole, double polowa_obwodu);

int main()
{
    int ret = -1;
    Trojkat t;
    double polowa_obwodu, pole, promien;
    t = wczytaj_trojkat();
    polowa_obwodu = oblicz_polowe_obwodu(t);
    pole = oblicz_pole(t, polowa_obwodu);
    promien = oblicz_promien_kola_wpisanego(pole, polowa_obwodu);
    printf("Boki trojkata: %lf %lf %lf\n", t.a, t.b, t.c);
    printf("Polowa obwodu: %lf\n", polowa_obwodu);
    printf("Pole trojkata: %lf\n", pole);
    printf("Promien kola wpisanego: %lf\n", promien);
    return 0;
}

Trojkat wczytaj_trojkat()
{
    int ret = -1;
    Trojkat t;
    do
    {
        printf("Podaj boki trojkata: ");
        ret = scanf("%lf %lf %lf", &t.a, &t.b, &t.c);
        if (ret != 3)
        {
            printf("Blad wczytywania danych!\n");
        }
        else if (!sprawdz_warunek_trojkata(t))
        {
            printf("Trojkat nie istnieje\n");
        }
        while (getchar() != '\n')
            ;
    } while (ret != 3 || !sprawdz_warunek_trojkata(t));
    return t;
}

int sprawdz_warunek_trojkata(Trojkat t)
{
    if (!(t.a + t.b > t.c))
    {
        return 0;
    }
    if (!(t.a + t.c > t.b))
    {
        return 0;
    }
    if (!(t.b + t.c > t.a))
    {
        return 0;
    }
    return 1;
}

double oblicz_polowe_obwodu(Trojkat t)
{
    double p = (t.a + t.b + t.c) / 2;
    return p;
}

double oblicz_pole(Trojkat t, double polowa_obwodu)
{
    double pole = sqrt(polowa_obwodu * (polowa_obwodu - t.a) * (polowa_obwodu - t.b) * (polowa_obwodu - t.c));
    return pole;
}

double oblicz_promien_kola_wpisanego(double pole, double polowa_obwodu)
{
    double promien = pole / polowa_obwodu;
    return promien;
}