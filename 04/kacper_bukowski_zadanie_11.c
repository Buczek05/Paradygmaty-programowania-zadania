#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>

#define INT_MAX 100

void fill_random(int *, int);
void print_min_max(int *, int n);
void free_table(int *);

int main(){
    int *t1, *t2, n;
    t1 = t2 = NULL;
    scanf("%d", &n);
    t1 = (int*)malloc((unsigned)n * sizeof(int));
    t2 = (int*)malloc((unsigned)n * sizeof(int));
    if (t1 == NULL || t2 == NULL){
        exit(1);
    }
    fill_random(t1, n);
    print_min_max(t1, n);
    memcpy(t2, t1, n * sizeof(int));
    for (int i = 0; i < n; i++) printf("%d ", t2[i]);
    free_table(t1);
    free_table(t2);
}

void fill_random(int *t, int n){
    srand(time(0));
    for (int i = 0; i < n; i++){
        t[i] = rand() % INT_MAX;
    }
}

void print_min_max(int *t, int n){
    int min = INT_MAX, max = 0;
    for (int i = 0; i < n; i++){
        printf("%d ", t[i]);
        if (t[i] < min) min = t[i];
        if (t[i] > max) max = t[i];
    }
    printf("\nMIN %d\n", min);
    printf("MAX %d\n", max);
}

void free_table(int *t){
    if (t){
        free(t);
        t = NULL;
    }
}