#include <stdio.h>

void fun(int &k) // &k tylko w kompilatorze c++
{
    k = 10 * k;
}

int main()
{
    int a = 10;
    fun(a);
    printf("%d ", a);
    return 0;
}