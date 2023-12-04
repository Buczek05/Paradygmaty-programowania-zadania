#include <stdio.h>
#include "math.h"

typedef struct CO {
    double re;
    double im;
} COMPLEX;

void rkw(double, double, double, COMPLEX *, COMPLEX *);
COMPLEX add_complex(COMPLEX *w1, COMPLEX *w2);

int main(){
    double a=1., b=2., c=3.;
    COMPLEX x1, x2;
    rkw(a, b, c, &x1, &x2);
    printf("x1 = %lf + %lfi\n", x1.re, x1.im);
    printf("x2 = %lf + %lfi\n", x2.re, x2.im);
    COMPLEX x1_plus_x2 = add_complex(&x1, &x2);
    printf("x1 + x2 = %lf + %lfi\n", x1_plus_x2.re, x1_plus_x2.im);
}

void rkw(double a, double b, double c, COMPLEX *x1, COMPLEX *x2){
    double delta = b*b - 4*a*c;
    if (delta >= 0){
        x1->re = (-b - sqrt(delta)) / (2*a);
        x1->im = 0;
        x2->re = (-b + sqrt(delta)) / (2*a);
        x2->im = 0;
    }
    else{
        x1->re = -b / (2*a);
        x1->im = -sqrt(fabs(pow(b/(2*a),2)+c/a));
        x2->re = -b / (2*a);
        x2->im = sqrt(fabs(pow(b/(2*a),2)+c/a));
    }
}

COMPLEX add_complex(COMPLEX *w1, COMPLEX *w2){
    COMPLEX w;
    w.re = w1->re + w2->re;
    w.im = w1->im + w2->im;
    return w;
}