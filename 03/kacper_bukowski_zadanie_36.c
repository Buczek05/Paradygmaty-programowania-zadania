#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable: 4996)
#define MAX_LINE 256

int get_letter_index(char, char *);
int get_morse_index(char *, char **, int);

int main() {
    char litery[] = {'a',136,'b','c',141,'d','e',171,'f','g','h','i','j','k','l',184,'m','n',196,'o',151,'p','q','r','s',230,'t','u','v','w','x','y','z',144,253,'A',132,'B','C',140,'D','E',162,'F','G','H','I','J','K','L',252,'M','N',193,'O',238,'P','Q','R','S',229,'T','U','V','W','X','Y','Z',143,251,' ','.',',','?',':','-','0','1','2','3','4','5','6','7','8','9','!',0};
    char *mors[] = {".-",".-.-","-...","-.-.","-.-..","-..",".","..-..","..-.","--.","....","..",".---","-.-",".-..",".-..-","--","-.","--.--","---","---.",".--.","--.-",".-.","...","...-...","-","..-","...-",".--","-..-","-.--","--..","--..-","--",".-",".-.-","-...","-.-.","-.-..","-..",".","..-..","..-.","--.","....","..",".---","-.-",".-..",".-..-","--","-.","--.--","---","---.",".--.","--.-",".-.","...","...-...","-","..-","...-",".--","-..-","-.--","--..","--..-","--",".",".-.-.-","--..--","..--..","---...","-....-","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.","!",0};
    char text[MAX_LINE], *w_text, letter, morseCode[MAX_LINE];
    int letter_number, mode;

    printf("Wybierz tryb: 1 dla kodowania, 2 dla dekodowania: ");
    scanf("%d", &mode);
    getchar(); // Pobierz znak nowej linii po wprowadzeniu liczby

    if (mode == 1) {
        printf("Wprowadź tekst do zakodowania:\n");
        w_text = fgets(text, MAX_LINE, stdin);
        while (*w_text) {
            if (*w_text == '\n') {
                printf("\n");
                w_text++;
                continue;
            }
            letter = *w_text;
            letter_number = get_letter_index(letter, litery);
            if (letter_number == -1) {
                printf("Nie znaleziono znaku w tablicy %c", letter);
                exit(1);
            }
            printf("%s ", mors[letter_number]);
            w_text++;
        }
    } else if (mode == 2) {
        printf("Wprowadź kod Morse'a do dekodowania:\n");
        while (scanf("%s", morseCode) == 1) {
            letter_number = get_morse_index(morseCode, mors, sizeof(litery));
            if (letter_number == -1) {
                printf("Nie znaleziono kodu Morse'a w tablicy %s", morseCode);
                exit(1);
            }
            printf("%c", litery[letter_number]);
        }
    } else {
        printf("Nieprawidłowy tryb.\n");
    }

    return 0;
}

int get_letter_index(char letter, char *litery) {
    int i = 0;
    while (litery[i]) {
        if (letter == litery[i]) return i;
        i++;
    }
    return -1;
}

int get_morse_index(char *morse, char **mors, int size) {
    for (int i = 0; i < size; i++) {
        if (mors[i] == 0) break; // Koniec tablicy
        if (strcmp(morse, mors[i]) == 0) return i;
    }
    return -1;
}
