#include <stdio.h>
#define MAX_LINE 256
#pragma warning(disable:4996)
int main()
{
    char text_1[MAX_LINE], text_2[MAX_LINE], *w_text_1, *w_text_2;
    printf("Podaj tekst pierwszy:\n");
    w_text_1 = fgets(text_1, MAX_LINE, stdin);
    printf("Podaj tekst drugi:\n");
    w_text_2 = fgets(text_2, MAX_LINE, stdin);
    printf("Podaj pozycje znaku w drugim tekscie:\n");
    int pozycja;
    scanf("%d", &pozycja);
    w_text_2 += pozycja;
    while (*w_text_1){
        w_text_1++;
    }
    w_text_1--;
    while (*w_text_2){
        *w_text_1 = *w_text_2;
        w_text_1++;
        w_text_2++;
    }
    printf("%s\n", text_1);
}