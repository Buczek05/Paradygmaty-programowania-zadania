#include <stdio.h>
#define PI 3.1415

void kolo(double, double *, double *);

int main()
{
    double r = 1, p, o;
    double *pp;
    pp = &p;
    kolo(r, &p, &o);
    kolo(r, pp, &o); // lub przekazanie wskaźnika pp
    printf("pole = %lf, obwod = %lf", p, o);
}

void kolo(double r, double *w1, double *w2)
{
    *w1 = PI * r * r;
    *w2 = 2 * PI * r;
}
