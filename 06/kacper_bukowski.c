#include "stdio.h"
#include "kacper_bukowski_data.c"

// sortowanie bombelkowe
STUDENT *sort_by_stypendium(STUDENT *head){
    STUDENT *current = head;
    STUDENT *next = head->next;
    STUDENT *prev = NULL;
    int swapped = 1;
    while (swapped){
        swapped = 0;
        while (next != NULL){
            if (current->stypendium > next->stypendium){
                if (prev == NULL){
                    current->next = next->next;
                    next->next = current;
                    head = next;
                    prev = next;
                } else {
                    current->next = next->next;
                    next->next = current;
                    prev->next = next;
                    prev = next;
                }
                swapped = 1;
            } else {
                prev = current;
                current = next;
            }
            next = current->next;
        }
        prev = NULL;
        current = head;
        next = head->next;
    }
    return head;
}

void print_students_stack(STUDENT *head){
    STUDENT *current = head;
    printf("Imie Nazwisko Rok Adres Stypendium\n");
    while (current != NULL){
        printf("%s %s %d %s %lf\n", current->imie, current->nazwisko, current->rok, current->adres, current->stypendium);
        current = current->next;
    }
}

void print_students_list(STUDENT **students){
    printf("Imie Nazwisko Rok Adres Stypendium\n");
    int i = 0;
    while (students[i]){
        printf("%s %s %d %s %lf\n", students[i]->imie, students[i]->nazwisko, students[i]->rok, students[i]->adres, students[i]->stypendium);
        i++;
    }
}

int get_students_count(STUDENT *head){
    int count = 0;
    STUDENT *current = head;
    while (current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

// compare function should return 1 if first student is "bigger" than second student
STUDENT **get_list_sort_by(STUDENT *head, int (*compare)(STUDENT *, STUDENT *)){
    int students_count = get_students_count(head);
    STUDENT **students, *temp, *current = head;
    students = (STUDENT **)malloc((students_count + 1) * sizeof(STUDENT *));
    for (int i = 0; i < students_count; i++){
        students[i] = current;
        current = current->next;
    }
    students[students_count] = NULL;
    int swapped = 1;
    while (swapped){
        swapped = 0;
        for (int i = 0; i < students_count - 1; i++){
            if (compare(students[i], students[i + 1])){
                temp = students[i];
                students[i] = students[i + 1];
                students[i + 1] = temp;
                swapped = 1;
            }
        }
    }
    return students;
}

int compare_by_nazwisko(STUDENT *first, STUDENT *second){
    return strcmp(first->nazwisko, second->nazwisko) > 0;
}

int main(){
    STUDENT *head = read_students("z_1_dane.txt"), **list;
    head = sort_by_stypendium(head);
    print_students_stack(head);
    printf("\n\n\n\n\n");
    list = get_list_sort_by(head, compare_by_nazwisko);
    print_students_list(list);
}