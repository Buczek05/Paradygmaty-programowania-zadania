#include <stdio.h>
#include <math.h>

typedef struct
{
    double a, b, c;
} Trojkat;
typedef struct
{
    double a, b;
} Prostokat;
typedef struct
{
    double r;
} Kolo;

Trojkat wczytaj_trojkat();
Prostokat wczytaj_kwadrat();
Prostokat wczytaj_prostokat();
Kolo wczytaj_kolo();

int sprawdz_warunek_trojkata(Trojkat t);
double oblicz_obwod_trojkat(Trojkat t);
double oblicz_pole_trojkat(Trojkat t, double obwod);

double oblicz_obwod_prostokat(Prostokat p);
double oblicz_pole_prostokat(Prostokat p);

double oblicz_obwod_kolo(Kolo k);
double oblicz_pole_kolo(Kolo k);

int main()
{
    double obwod_trokat, pole_trokat, obwod_kwadrat, pole_kwadrat, obwod_prostokat, pole_prostokat, obwod_kolo, pole_kolo;
    Trojkat t;
    Prostokat k, p;
    Kolo ko;

    t = wczytaj_trojkat();
    obwod_trokat = oblicz_obwod_trojkat(t);
    pole_trokat = oblicz_pole_trojkat(t, obwod_trokat);
    printf("Boki trojkata: %lf %lf %lf\n", t.a, t.b, t.c);
    printf("Obwod trojkata: %lf\n", obwod_trokat);
    printf("Pole trojkata: %lf\n", pole_trokat);

    k = wczytaj_kwadrat();
    obwod_kwadrat = oblicz_obwod_prostokat(k);
    pole_kwadrat = oblicz_pole_prostokat(k);
    printf("Bok kwadratu: %lf\n", k.a);
    printf("Obwod kwadratu: %lf\n", obwod_kwadrat);
    printf("Pole kwadratu: %lf\n", pole_kwadrat);

    p = wczytaj_prostokat();
    obwod_prostokat = oblicz_obwod_prostokat(p);
    pole_prostokat = oblicz_pole_prostokat(p);
    printf("Boki prostokata: %lf %lf\n", p.a, p.b);
    printf("Obwod prostokata: %lf\n", obwod_prostokat);
    printf("Pole prostokata: %lf\n", pole_prostokat);

    ko = wczytaj_kolo();
    obwod_kolo = oblicz_obwod_kolo(ko);
    pole_kolo = oblicz_pole_kolo(ko);
    printf("Promien kola: %lf\n", ko.r);
    printf("Obwod kola: %lf\n", obwod_kolo);
    printf("Pole kola: %lf\n", pole_kolo);
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
        else if (t.a < 0 || t.b < 0 || t.c < 0)
        {
            printf("Boki nie moga byc ujemne!\n");
        }
        while (getchar() != '\n')
            ;
    } while (ret != 3 || !sprawdz_warunek_trojkata(t) || t.a < 0 || t.b < 0 || t.c < 0);
    return t;
}
Prostokat wczytaj_kwadrat()
{
    int ret = -1;
    Prostokat k;
    do
    {
        printf("Podaj bok kwadratu: ");
        ret = scanf("%lf", &k.a);
        if (ret != 1)
        {
            printf("Blad wczytywania danych!\n");
        }
        else if (k.a < 0)
        {
            printf("Bok nie moze byc ujemny!\n");
        }
        while (getchar() != '\n')
            ;
    } while (ret != 1 || k.a < 0);
    k.b = k.a;
    return k;
}
Prostokat wczytaj_prostokat()
{
    int ret = -1;
    Prostokat p;
    do
    {
        printf("Podaj boki prostokata: ");
        ret = scanf("%lf %lf", &p.a, &p.b);
        if (ret != 2)
        {
            printf("Blad wczytywania danych!\n");
        }
        else if (p.a < 0 || p.b < 0)
        {
            printf("Boki nie moga byc ujemne!\n");
        }
        while (getchar() != '\n')
            ;
    } while (ret != 2 || p.a < 0 || p.b < 0);
    return p;
}
Kolo wczytaj_kolo()
{
    int ret = -1;
    Kolo k;
    do
    {
        printf("Podaj promien kola: ");
        ret = scanf("%lf", &k.r);
        if (ret != 1)
        {
            printf("Blad wczytywania danych!\n");
        }
        else if (k.r < 0)
        {
            printf("Promien nie moze byc ujemny!\n");
        }
        while (getchar() != '\n')
            ;
    } while (ret != 1 || k.r < 0);
    return k;
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
double oblicz_obwod_trojkat(Trojkat t)
{
    return t.a + t.b + t.c;
}
double oblicz_pole_trojkat(Trojkat t, double obwod)
{
    double p = obwod / 2;
    return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}

double oblicz_obwod_prostokat(Prostokat p)
{
    return 2 * p.a + 2 * p.b;
}
double oblicz_pole_prostokat(Prostokat p)
{
    return p.a * p.b;
}

double oblicz_obwod_kolo(Kolo k)
{
    return 2 * M_PI * k.r;
}
double oblicz_pole_kolo(Kolo k)
{
    return M_PI * k.r * k.r;
}