#include "stdio.h"
#include "math.h"

double funkcja(double x, double f(double))
{
    return x*x + (*f)(x);
}

int main(){
    double x = 0.0;
    printf("sin f(x) = %lf\n", funkcja(x, sin));
    printf("cos f(x) = %lf\n", funkcja(x, cos));
}