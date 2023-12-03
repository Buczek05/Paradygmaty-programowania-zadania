#include <memory.h>
#include <stdio.h>
int main(void)
{
    char buffer[] = "This is a test of the memset function";
    printf("Before: %s\n", buffer);
    memset(buffer, '*', 4);
    printf("After: %s\n", buffer);
}