#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = NULL;
    fp = fopen("plik_tekstowy.txt", "r");
    char znak;
    if (!fp)
    {
        printf("Nie moge otworzyc pliku");
        getchar();
        exit(1);
    }

    while (fscanf(fp, "%c", &znak) != EOF)
    {
        printf("%c", znak);
    }
    fclose(fp);
    fp = NULL;
    return 0;
}