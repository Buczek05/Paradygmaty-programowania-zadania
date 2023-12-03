#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "kacper_bukowski_zadanie_17_util_1.c"
#include "kacper_bukowski_zadanie_17_util_2.c"
#include "kacper_bukowski_zadanie_17_util_3.c"
#include "kacper_bukowski_zadanie_17_util_4.c"
#include "kacper_bukowski_zadanie_17_util_5.c"

void argumenty(int argc, char *argv[]);
int main(int argc, char *argv[])
{
    FILE *fd;
    double **mac;
    int wym;
    argumenty(argc, argv);
    if (!(fd = fopen(argv[1], "r"))) error(2, "dane");
    fscanf(fd, "%d", &wym);
    mac = DajMac_1(wym, wym);
    CzytMac(fd, mac, wym , wym);
    int row, col;
    double suma = 0;
    for (row = 0; row < wym; row++){
        for (col = 0; col < wym; col++){
            if (row == col && sin(mac[row][col]) >= 0){
                suma += mac[row][col];
            }
            if (row + col == wym - 1 && sin(mac[row][col]) >= 0.5){
                suma += mac[row][col];
            }
        }
    }
    printf("%lf\n", suma);

}
void argumenty(int argc, char *argv[])
{
    int len;
    char *usage;
    if (argc != 2)
    {
        len = strlen(argv[0]) + 19;
        if (!(usage = (char*)malloc((unsigned)len * sizeof(char))))
            error(3, "tablica usage");
        strcpy(usage, argv[0]);
        strcat(usage, " file_in");
        error(4, usage);
    }
}