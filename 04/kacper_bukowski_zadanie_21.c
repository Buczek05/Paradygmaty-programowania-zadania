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
    FILE *fd;
    double **mac;
    int wym;
    double range_a, range_b; // range(mac, b)
    argumenty(argc, argv);
    if (!(fd = fopen(argv[1], "r"))) error(2, "dane");
    fscanf(fd, "%d %lf %lf", &wym, &range_a, &range_b);
    mac = DajMac_1(wym, wym);
    CzytMac(fd, mac, wym , wym);
    int row, col;
    double suma = 0;
    for (row = 0; row < wym; row++){
        for (col = 0; col < wym; col++){
            if (row > col && range_a <= mac[row][col] && mac[row][col] <= range_b){
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