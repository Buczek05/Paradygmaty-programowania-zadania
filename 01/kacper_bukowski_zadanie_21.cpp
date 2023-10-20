#include <stdio.h>
#include <locale.h>
#include <math.h>
#pragma warning (disable: 4996)

int main()
{
    setlocale(LC_ALL, "Polish");
    double x = 3.14, y = 12.56, z = 7;
    int k = 2, m = 4;
    double w1, w2, w3, w4, w5;
    w1 = pow((x/(y*z)), 1./3) * log(x*x + y*y);
    printf("w1 = %.8lf\n", w1);
    w2 = sin(k*(x/2))*cos(m*y) + y*exp(2*x - 1);
    printf("w2 = %.8lf\n", w2);
    w3 = fabs(x/(2*(y*y) + 1)) + sqrt(y/((z*z)+3)) + 5* pow(y+z, 3);
    printf("w3 = %.8lf\n", w3);
    w4 = ((x/(y*z)) * pow(z+1, 1./3)) + pow((x*x)+(z*z)+1, 1./k) - fabs(y);
    printf("w4 = %.8lf\n", w4);
    w5 = 1/(sqrt(x*x+y*y+k*k)) + (1/x) * sin(k*y);
    printf("w5 = %.8lf\n", w5);
    return 0;
}
