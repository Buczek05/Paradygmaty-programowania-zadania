#include <stdio.h>
#include <stdlib.h>

int czy_jest_szukana_cyfra(int x, int szukana_cyfra) {
    while (x > 0) {
        if (x % 10 == szukana_cyfra) {
            return 1;
        }
        x = x / 10;
    }
    return 0;
}

int main() {
    int n, szukana_cyfra, x, stoper, ilosc = 0;

    printf("n=");
    scanf("%d", &n);

    printf("stoper=");
    scanf("%d", &stoper);

    printf("szukana cyfra=");
    scanf("%d", &szukana_cyfra);
    if (szukana_cyfra < 0 || szukana_cyfra > 9) {
        printf("SZUKANA MUSI BYC CYFRA NIE LICZBA\nSZUKANA = %d\n", szukana_cyfra);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("x=");
        scanf("%d", &x);

        if (x != stoper) {
            ilosc += czy_jest_szukana_cyfra(x, szukana_cyfra);
        } else {
            n = i;
        }
    }
    printf("ilosc=%d\n", ilosc);
    return 0;
}