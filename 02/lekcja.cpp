#include <stdio.h>
#include <cstring>

int main()
{
    int arr[20];
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", arr[i]);
    }
}