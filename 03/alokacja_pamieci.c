#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *ptr = malloc(256*sizeof(char));
    if (ptr == NULL)
    {
        printf("Nie udalo sie zaalokowac pamieci\n");
        return 1;
    }
    sprintf(ptr, "zaalokowano %d bajtow", 256);
    printf("%s\n", ptr);
    char *ptr2 = malloc(256*sizeof(char));
    sprintf(ptr2, "Nie zmienny text");
    printf("%s\n", ptr2);
    ptr2 = realloc(ptr2, 512*sizeof(char));
    if (ptr2 == NULL)
    {
        printf("Nie udalo sie zaalokowac pamieci\n");
        return 1;
    }
    printf("%s\n", ptr2);
}