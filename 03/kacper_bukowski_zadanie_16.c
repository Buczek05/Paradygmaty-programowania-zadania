#include <stdio.h>
#define MAX_LINE 256
int main()
{
    char text_1[MAX_LINE], text_2[MAX_LINE], *w_text_1, *w_text_2;
    printf("Podaj tekst pierwszy:\n");
    w_text_1 = fgets(text_1, MAX_LINE, stdin);
    printf("Podaj tekst drugi:\n");
    w_text_2 = fgets(text_2, MAX_LINE, stdin);
    while (*w_text_1)
    {
        w_text_1++;
    }
    w_text_1--; // cofniecie przed znak nowej linii
    do{
        *w_text_1 = *w_text_2;
        w_text_1++;
        w_text_2++;
    }while (*w_text_2);
    printf("%s\n", text_1);
}