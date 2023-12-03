#include <memory.h>
#include <stdio.h>
int main(void)
{
    char str[256];
    double aa[200];
    double cc[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    double dd[5] = { 20, 30, 40, 50, 60 };
    memset((void *)str, 0, 256 * sizeof(char)); //OK
    memset((void *)str, ' ', 256 * sizeof(char)); //!OK–pisanie po pamięci
    memset((void *)str, ' ', 255 * sizeof(char)); //OK
    memset((void *)aa, 0, 200 * sizeof(double)); //OK
    memcpy((void *)&cc[3], (const void *)&dd[2], 2 * sizeof(double));
}