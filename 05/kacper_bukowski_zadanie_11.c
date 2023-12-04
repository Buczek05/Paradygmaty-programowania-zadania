#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFOR 80
#define MAX 10

struct student {
    char* imie;
    char* nazwisko;
    int rok;
    char* adres;
    double stypendium;
};

FILE *fd = NULL;

int main(){
    char bufor[MAX_BUFOR];
    struct student t[MAX];
    int i = 0, poz = 0;
    double max_s = 0;
    unsigned len;
    fd = fopen("05/z_11_dane.txt", "r");
    if (fd == NULL){
        printf("Nie udalo sie otworzyc pliku\n");
        exit(1);
    }
    while (i < MAX && fgets(bufor, MAX_BUFOR, fd) != (char *)NULL){
        len = (unsigned)strlen(bufor);
        bufor[len - 1] = '\0';
        t[i].imie = (char *)malloc(len * sizeof(char));
        strcpy(t[i].imie, bufor);

        if (fgets(bufor, MAX_BUFOR, fd) == (char *)NULL) break;
        len = (unsigned)strlen(bufor);
        bufor[len - 1] = '\0';
        t[i].nazwisko = (char *)malloc(len * sizeof(char));
        strcpy(t[i].nazwisko, bufor);

        if (fgets(bufor, MAX_BUFOR, fd) == (char *)NULL) break;
        t[i].rok = atoi(bufor);

        if (fgets(bufor, MAX_BUFOR, fd) == (char *)NULL) break;
        len = (unsigned)strlen(bufor);
        bufor[len - 1] = '\0';
        t[i].adres = (char *)malloc(len * sizeof(char));
        strcpy(t[i].adres, bufor);

        if (fgets(bufor, MAX_BUFOR, fd) == (char *)NULL) break;
        t[i].stypendium = atof(bufor);
        if (t[i].stypendium > max_s){
            max_s = t[i].stypendium;
            poz = i;
        }
        i++;
    }
    printf("Student z najwyzszym stypendium:\n");
    printf("%s\n%s\n%d\n%s\n%lf\n", t[poz].imie, t[poz].nazwisko, t[poz].rok, t[poz].adres, t[poz].stypendium);
}