#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double);
double fp(double);
double g(double);
double gp(double);

int newton(double *, int, double, double(*f1)(double), double(*f2)(double));

/* start 0.5 -> 0 0.8 -> -1.8954 1.0 -> 1.8954 */
int main() {
    double x0 = 0.8, eps = 0.001;
    int n = 100;
// printf("podaj:\n przybl. dokl. maks.iter.\n");
// scanf("%lf %lf %d", &x0,&eps,&n);
    if (!newton(&x0, n, eps, f, fp))
        printf("rozwiazanie= %lf wart.= %lf\n", x0, f(x0));
    else
        printf("Brak zbieznosci\n");
    x0 = 0.8;
    if (!newton(&x0, n, eps, g, gp))
        printf("rozwiazanie= %lf wart.= %lf\n", x0, f(x0));
    else
        printf("Brak zbieznosci\n");
    system("pause");
}

int newton(double *x, int n, double eps, double(*f1)(double), double(*f2)(double)) {
    double x1;
    int i = 0;
    do {
        x1 = -(*f1)(*x) / (*f2)(*x);
        *x += x1;
        if (fabs(x1) < eps) return 0;
    } while (i++ < n);
    return 1;
}

double f(double x) {
    return sin(x) - .5 * x;
}

double fp(double x) {
    return cos(x) - .5;
}

double g(double x) {
    return tan(x) - 2 * x;
}

double gp(double x) {
    return 1 / pow(cos(x), 2) - 2;
}