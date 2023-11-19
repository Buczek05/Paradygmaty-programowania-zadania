#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)
#define MAX_LINE 256
int main(){
    char *text = malloc(MAX_LINE * sizeof(char)), *w_text, *word_start, letter = ':';
    int word_number, word_counter = 0;
    printf("Podaj text: ");
    w_text = fgets(text, MAX_LINE, stdin);
    printf("Podaj numer słowa: ");
    scanf("%d", &word_number);
    while (*w_text){
        if (letter == ':') {
            word_counter++;
            if (word_counter == word_number){
                word_start = w_text;
            }
            if (word_counter == word_number + 1){
                while (word_start != w_text-1){
                    putchar(*word_start);
                    word_start++;
                }
                break;
            }
        }
        letter = *w_text;
        w_text++;
    }
    if (word_counter == word_number){
        printf("%s", word_start);
    }
}