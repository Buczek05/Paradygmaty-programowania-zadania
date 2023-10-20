#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

typedef struct {
    double a;
    double b;
    double c;
} Dane;

typedef struct {
    double x1;
    double x2;
} WynikWieksza;

typedef struct {
    double r1;
    double r2;
    double u1;
    double u2;
} WynikMniejsza;

Dane wprowadzanie_danych();
double liczenie_delty(Dane dane);
WynikWieksza liczenie_dla_delty_wiekszej(Dane dane, double delta);
double liczenie_dla_delty_rownej(Dane dane, double delta);
WynikMniejsza liczenie_dla_delty_mniejszej(Dane dane, double delta);

int main(){
    double delta;
    Dane dane;
    dane = wprowadzanie_danych();
    printf("Wprowadzone liczby: a = %lf, b = %lf, c = %lf\n", dane.a, dane.b, dane.c);
    delta = liczenie_delty(dane);
    printf("Delta = %lf\n", delta);
    if(delta > 0){

        WynikWieksza wynik = liczenie_dla_delty_wiekszej(dane, delta);
        printf("x1 = %lf, x2 = %lf\n", wynik.x1, wynik.x2);
    }
    else if(delta == 0){
        double x = liczenie_dla_delty_rownej(dane, delta);
        printf("x = %d\n", x);
    }
    else{
        WynikMniejsza wynik = liczenie_dla_delty_mniejszej(dane, delta);
        printf("r1 = %lf, u1 = %lfi, r2 = %lf, u2 =  %lfi\n", wynik.r1, wynik.u1, wynik.r2, wynik.u2);
    }
    return 0;
}

Dane wprowadzanie_danych(){
    Dane dane;
    int ret = -1;
    do
    {
        printf("Podaj 3 liczby: ");
        ret = scanf("%le %le %le", &dane.a, &dane.b, &dane.c);
        if (ret != 3) {
            printf("Niepoprawny typ danych\n");
        }
        else if (dane.a == 0.) {
            printf("To nie jest rownanie kwadratowe\n");
        }
        while ((getchar()) != '\n'); // aby nie zaczytać powyższego printa do scanf
    } while(ret != 3 || dane.a == 0.);
    return dane;
}

double liczenie_delty(Dane dane){
    return dane.b * dane.b - 4 * dane.a * dane.c;
}

WynikWieksza liczenie_dla_delty_wiekszej(Dane dane, double delta){
    WynikWieksza wynik;
    wynik.x1 = (-dane.b - sqrt(delta)) / (2 * dane.a);
    wynik.x2 = (-dane.b + sqrt(delta)) / (2 * dane.a);
    return wynik;
}

double liczenie_dla_delty_rownej(Dane dane, double delta){
    return -dane.b / (2 * dane.a);
}

WynikMniejsza liczenie_dla_delty_mniejszej(Dane dane, double delta){
    WynikMniejsza wynik;
    wynik.r1 = -dane.b / (2 * dane.a);
    wynik.r2 = wynik.r1;
    wynik.u1 = sqrt(-delta) / (2 * dane.a);
    wynik.u2 = -sqrt(-delta) / (2 * dane.a);
    return wynik;
}