#include <stdio.h>
#include <string.h>

int main()
{

    char ptr[256] = "zaalokowano 256 bajtow";
    printf("%s\n", ptr);
    sprintf(ptr, "Nowy text");
    printf("%s\n", ptr);
//    ptr = "Inny nowy text";  Tak nie zadziała
    strcpy(ptr, "Wpisujemy nowy text ale jeśli braknie miejsca to on zniknie");
    printf("%s\n", ptr);
    strcat(ptr, " a ten text zostanie dodany na koniec");
    printf("%s\n", ptr);
    int value = strcmp(ptr, "Wpisujemy nowy text ale jeśli braknie miejsca to on zniknie");
    printf("%d\n", value); // 0 oznacza że są takie same
    int length = strlen(ptr); // strlen zwraca długość stringa
    printf("%d\n", length);
    putchar(ptr[10]); // putchar wypisuje znak
}