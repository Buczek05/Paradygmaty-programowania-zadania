# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct STUDENT {
    char *imie;
    char *nazwisko;
    int rok;
    double stypendium;
    char *adres;
    struct STUDENT *next;
    struct STUDENT *prev;
} STUDENT;

STUDENT *read_students(char *filename){
    FILE *fd = NULL;
    char bufor[80];
    STUDENT *head = NULL;
    STUDENT *current = NULL;
    fd = fopen(filename, "r");
    if (fd == NULL){
        printf("Nie udalo sie otworzyc pliku\n");
        exit(1);
    }
    while (fgets(bufor, 80, fd) != (char *)NULL){
        STUDENT *student = (STUDENT *)malloc(sizeof(STUDENT));
        student->imie = (char *)malloc(80 * sizeof(char));
        student->nazwisko = (char *)malloc(80 * sizeof(char));
        student->adres = (char *)malloc(80 * sizeof(char));
        sscanf(bufor, "%s %s %d %s %lf", student->imie, student->nazwisko, &student->rok, student->adres, &student->stypendium);
        if (head == NULL){
            head = student;
            current = student;
        } else {
            current->next = student;
            student->prev = current;
            current = student;
        }
    }
    current->next = NULL;
    return head;
}
