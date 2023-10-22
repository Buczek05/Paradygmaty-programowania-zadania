#include <stdio.h>

double count(double, double, int *);

int main()
{
    double x = 10.5, y = 1.5;
    int wzor = -1;
    double wynik = count(x, y, &wzor);
    if (wzor == -1)
        printf("Blad, nie zastosowano zadnego wzoru");
    else
        printf("wynik = %lf, zastosowano wzor numer %d", wynik, wzor);
    return 0;
}

double count(double x, double y, int *w)
{
    double z = 0.0;
    if (x * x + y * y <= 1)
    {
        z = x * x + y;
        *w = 1;
    }
    else if (y > x + 5)
    {
        z = 2 * x + y * y;
        *w = 2;
    }
    else if (x * x + y * y > 1 && y <= x + 5)
    {
        z = (x * x / 2) + y;
        *w = 3;
    }
    return z;
}