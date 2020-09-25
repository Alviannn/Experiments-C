#include <stdio.h>
#include <stdlib.h>

int numbers[] = {5, 2, 1, 3, 4};
int size = sizeof(numbers) / sizeof(numbers[0]);

int main() {
    // -------------- Debug -------------- //
    printf("Size    : %d\n", size);
    printf("Numbers : ");

    for (int i = 0; i < size; i++)
        printf("%d ", numbers[i]);

    printf("\n");
    // -------------- Debug -------------- //

    // -------------- Sorting -------------- //
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];

                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    // -------------- Sorting -------------- //

    printf("Result: ");
    for (int i = 0; i < size; i++)
        printf("%d ", numbers[i]);

    return 0;
}