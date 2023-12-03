#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "kacper_bukowski_zadanie_12_util_1.c"
#include "kacper_bukowski_zadanie_12_util_2.c"
#include "kacper_bukowski_zadanie_12_util_3.c"

void argumenty(int, char **);
int main(int argc, char *argv[])
{
    double *x, *y, *z, s, mx, my;
    FILE *fw, *fd;
    int n, k;
    argumenty(argc, argv);
    if (!(fd = fopen(argv[1], "r"))) error(2, "dane");
    if (!(fw = fopen(argv[2], "w"))) error(2, "wyniki");
    fscanf(fd, "%d", &n);

    x = DajWekt(n);
    y = DajWekt(n);
    z = DajWekt(n);

    CzytWekt(fd, x, n);
    CzytWekt(fd, y, n);

    DodWekt(x, y, z, n);
    s = IloczynSkal(x, y, n);
    mx = MaxElem(x, n);
    my = MaxElem(y, n);
    PiszWekt(fw, z, n);
    fprintf(fw, "\nilocz.skal=%lf mx=%lf my=%lf\n", s, mx, my);
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