#include <stdio.h>
#include <stdlib.h>

int main(){
    short a = 32000;
    a += a;
    double **tab_a, *tab_b;
    int n = 10, m = 5;
    tab_b = (double *)malloc(sizeof(double) * n * m );
    if (!tab_b)
    {
//błąd alokacji
    }
    tab_a = (double **)malloc(sizeof(double *) * n);
    if (!tab_a)
    {
//błąd alokacji
    }
    for (int i = 0; i < n; i++)
    {
        tab_a[i] = &tab_b[ m * i ];
    }
    if (tab_b)
    {
        free(tab_b); // free(tab_a[0]);
        tab_b = NULL;
    }
    if (tab_a)
    {
        free(tab_a);
        tab_a = NULL;
    }
}