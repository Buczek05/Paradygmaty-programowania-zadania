#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 256
#define MAX_LINES 200
FILE *fd;
void read_data_from_file(char **lines);
int main()
{
    char **lines = malloc(MAX_LINES * sizeof(char));
    if (lines == NULL){
        perror("Error with allocation memory");
        exit(1);
    }
    read_data_from_file(lines);
    char new_text[MAX_LINE];
    int choose_line;
    printf("Podaj tekst do wstawienia: ");
    fgets(new_text, MAX_LINE, stdin);
    printf("Podaj numer wiersza: ");
    scanf("%d", &choose_line);
    getchar();
    for (int i = MAX_LINES; i > choose_line; i--){
        lines[i] = lines[i-1];
    }
    lines[choose_line] = malloc(strlen(new_text)+1);
    strcpy(lines[choose_line], new_text);
    for (int i = 0; i < MAX_LINES && lines[i]; i++){
        printf("%s", lines[i]);
    }
}

void read_data_from_file(char **lines){
    FILE *file = fopen("03/dane.txt", "r");
    if (file == NULL){
        perror("Error opening file");
        exit(1);
    }
    char buffer[MAX_LINE];
    int line_count = 0;
    while (fgets(buffer, MAX_LINE, file)){
        lines[line_count] = malloc(strlen(buffer)+1);
        if (lines[line_count] == NULL){
           perror("Error with allocation memory");
           exit(1);
        }
        strcpy(lines[line_count], buffer);
        line_count++;
    }
    fclose(file);
}