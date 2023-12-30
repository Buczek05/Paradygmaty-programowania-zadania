#include <stdio.h>
#include <string.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int i;

    FILE *file = fopen("data.bin", "wb");
    if (file == NULL) {
        perror("Nie można otworzyć pliku do zapisu");
        return 1;
    }
    fwrite(arr, sizeof(int), 5, file);
    fclose(file);

    memset(arr, 0, sizeof(arr));

    file = fopen("data.bin", "rb");
    if (file == NULL) {
        perror("Nie można otworzyć pliku do odczytu");
        return 1;
    }
    fread(arr, sizeof(int), 5, file);
    fclose(file);

    for (i = 0; i < 5; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
