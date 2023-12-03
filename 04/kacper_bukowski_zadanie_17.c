#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "kacper_bukowski_zadanie_17_util_1.c"
#include "kacper_bukowski_zadanie_17_util_2.c"
#include "kacper_bukowski_zadanie_17_util_3.c"
#include "kacper_bukowski_zadanie_17_util_4.c"
#include "kacper_bukowski_zadanie_17_util_5.c"

void argumenty(int argc, char *argv[]);
int main(int argc, char *argv[])
{
    FILE *fw, *fd;
    double *x, *y;
    double **a, **b, **c;
    int n, m;
    argumenty(argc, argv);
    if (!(fd = fopen(argv[1], "r"))) error(2, "dane");
    if (!(fw = fopen(argv[2], "w"))) error(2, "wyniki");
    fscanf(fd, "%d %d", &n, &m);
    x = DajWekt(m);
    y = DajWekt(m);
    a = DajMac_1(n, m);
    b = DajMac_1(n, m);
    c = DajMac_1(n, m);
    CzytMac(fd, a, n, m);
    CzytWekt(fd, x, m);
    CzytMac(fd, b, n, m);

    DodMac(a, b, c, n, m);
    printf("Suma macierzy\n");
    PiszMac(stdout, c, n, m);
    fprintf(fw, "Suma macierzy\n");
    PiszMac(fw, c, n, m);

    c = DajMac_1(n, m);
    Mac_x_Mac(a, b, c, n, m, n);
    printf("Iloczyn macierzy\n");
    PiszMac(stdout, c, n, m);
    fprintf(fw, "Iloczyn macierzy\n");
    PiszMac(fw, c, n, m);

    Mac_x_Wekt(a, x, y, n, m);
    printf("Wektor\n");
    PiszWekt(stdout, y, n);
    fprintf(fw, "Wektor\n");
    PiszWekt(fw, y, n);
}
void argumenty(int argc, char *argv[])
{
    int len;
    char *usage;
    if (argc != 3)
    {
        len = strlen(argv[0]) + 19;
        if (!(usage = (char*)malloc((unsigned)len * sizeof(char))))
            error(3, "tablica usage");
        strcpy(usage, argv[0]);
        strcat(usage, " file_in file_out");
        error(4, usage);
    }
}