#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int wez_rok_teraz();

int main()
{
    int ret = -1;
    int rok_urodzenia_uzytkownika = 0;
    int rok_teraz = wez_rok_teraz();
    printf("Rok teraz: %d\n", rok_teraz);
    do
    {
        printf("Podaj rok urodzenia: ");
        ret = scanf("%d", &rok_urodzenia_uzytkownika);
        if (ret != 1)
        {
            printf("Podano nieprawidlowy rok urodzenia!\n");
        }
        else if (rok_teraz < rok_urodzenia_uzytkownika)
        {
            printf("Podano rok urodzenia wiekszy niz obecny rok!\n");
        }
        while (getchar() != '\n')
            ;
    } while (ret != 1 || rok_teraz < rok_urodzenia_uzytkownika);
    printf("Masz rocznikowo %d lat\n", rok_teraz - rok_urodzenia_uzytkownika);
    return 0;
}

int wez_rok_teraz()
{
    char date[] = __DATE__;
    char *last_word = strtok(date, " "); // Pobieramy pierwsze słowo

    char *temp;
    while ((temp = strtok(NULL, " ")) != NULL)
    {
        last_word = temp; // Przechodzimy przez wszystkie słowa, aż do ostatniego
    }
    return atoi(last_word); // ASCII to integer - a to i
}