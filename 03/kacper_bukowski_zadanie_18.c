#include <stdio.h>
#define MAX_LINE 256
#pragma warning(disable:4996)
int main()
{
    char text[MAX_LINE] = "Ala ma kota", *w_text = text, *first_char = text, old_char = text[0], next_char;
    printf("%s\n", text);
    while (*(w_text+sizeof(char)))
    {
        next_char = *(w_text+sizeof(char));
        *(w_text+sizeof(char)) = old_char;
        old_char = next_char;
        w_text++;
    }
    *first_char = old_char;
    printf("%s\n", text);
}