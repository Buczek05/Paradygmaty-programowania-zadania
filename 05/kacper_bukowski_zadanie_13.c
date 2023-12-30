#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFOR 80
#define MAX 10

typedef struct student {
    char* imie;
    char* nazwisko;
    int rok;
    char* adres;
    double stypendium;
    struct student *next;
} STUDENT;

STUDENT *head;

FILE *fd = NULL;

void list1(FILE *file);
void print_students();
void print_student(STUDENT *student);
STUDENT *get_student_with_highest_stypendium();
STUDENT *create_student(char *imie, char *nazwisko, int rok, char *adres, double stypendium);
void add_new_first_student(STUDENT *student);
void add_new_last_student(STUDENT *student);
int count_students();
void free_student(STUDENT *student);
void free_string(char *string);
void delete_first_student();
void delete_last_student();
void delete_student(STUDENT *student);

int main(){
    fd = fopen("05/z_11_dane.txt", "r");
    if (fd == NULL){
        printf("Nie udalo sie otworzyc pliku\n");
        exit(1);
    }
    list1(fd);
    print_students();
    printf("Student z najwyzszym stypendium:\n");
    print_student(get_student_with_highest_stypendium());
    STUDENT *new_student = create_student("Jan", "Kowalski", 1999, "Gdynia", 1000);
    add_new_first_student(new_student);

    printf("NOWA LISTA\n");
    print_students();

    new_student = create_student("Grażyna", "Kowalska", 1999, "Gdynia", 1000);
    add_new_last_student(new_student);
    printf("NOWA LISTA\n");
    print_students();

    delete_first_student();
    printf("NOWA LISTA\n");
    print_students();

    delete_last_student();
    printf("NOWA LISTA\n");
    print_students();
}

void list1(FILE *file){
    unsigned len;
    STUDENT *current, *prev = NULL;
    char *bufor = (char *)malloc(MAX_BUFOR * sizeof(char));
    while (fgets(bufor, MAX_BUFOR, fd) != (char *)NULL){
        current = (STUDENT *)malloc(sizeof(STUDENT));
        if (prev != NULL) prev->next = current;
        else head = current;

        len = (unsigned)strlen(bufor);
        bufor[len - 1] = '\0';
        current->imie = (char *)malloc(len * sizeof(char));
        strcpy(current->imie, bufor);

        if (fgets(bufor, MAX_BUFOR, fd) == (char *)NULL) break;
        len = (unsigned)strlen(bufor);
        bufor[len - 1] = '\0';
        current->nazwisko = (char *)malloc(len * sizeof(char));
        strcpy(current->nazwisko, bufor);

        if (fgets(bufor, MAX_BUFOR, fd) == (char *)NULL) break;
        current->rok = atoi(bufor);

        if (fgets(bufor, MAX_BUFOR, fd) == (char *)NULL) break;
        len = (unsigned)strlen(bufor);
        bufor[len - 1] = '\0';
        current->adres = (char *)malloc(len * sizeof(char));
        strcpy(current->adres, bufor);

        if (fgets(bufor, MAX_BUFOR, fd) == (char *)NULL) break;
        current->stypendium = atof(bufor);

        prev = current;
    }
}

void print_students(){
    STUDENT *current = head;
    printf("%12s | %12s | %5s | %30s | %10s | %16s | %16s \n", "IMIE", "NAZWISKO", "ROK", "ADRES", "STYPENDIUM", "ADRES OBIEKTU", "ADRES NEXT");
    while (current != NULL){
        print_student(current);
        current = current->next;
    }
    printf("COUNT: %d\n\n\n", count_students());
}

void print_student(STUDENT *student) {
    printf("%12s | %12s | %5d | %30s | %10.2lf | %16p | %16p\n", student->imie, student->nazwisko, student->rok, student->adres, student->stypendium, student, student->next);
}

STUDENT *get_student_with_highest_stypendium(){
    STUDENT *current = head;
    STUDENT *max = head;
    while (current != NULL){
        if (current->stypendium > max->stypendium) max = current;
        current = current->next;
    }
    return max;
}

STUDENT *create_student(char *imie, char *nazwisko, int rok, char *adres, double stypendium){
    STUDENT *student;
    student = (STUDENT *)malloc(sizeof(STUDENT));
    student->imie = (char *)malloc(strlen(imie) * sizeof(char));
    student->nazwisko = (char *)malloc(strlen(nazwisko) * sizeof(char));
    student->adres = (char *)malloc(strlen(adres) * sizeof(char));
    strcpy(student->imie, imie);
    strcpy(student->nazwisko, nazwisko);
    student->rok = rok;
    strcpy(student->adres, adres);
    student->stypendium = stypendium;
    return student;
}

void add_new_first_student(STUDENT *student){
    student->next = head;
    head = student;
}

void add_new_last_student(STUDENT *student){
    STUDENT *current = head;
    while (current->next != NULL) current = current->next;
    current->next = student;
    student->next = NULL;
}

int count_students(){
    int count = 0;
    STUDENT * current = head;
    while (current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

void free_student(STUDENT *student){
    if (student){
        free_string(student->imie);
        free_string(student->nazwisko);
        free_string(student->adres);
        free(student);
        student = NULL;
    }
}

void free_string(char *string){
    if (string){
        free(string);
        string = NULL;
    }
}

void delete_first_student(){
    STUDENT *current = head;
    head = head->next;
    free_student(current);
}

void delete_last_student(){
    STUDENT *current = head;
    STUDENT *prev = NULL;
    while (current->next != NULL){
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free_student(current);
}