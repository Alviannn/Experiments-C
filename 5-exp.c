#include <stdio.h>
#include <stdlib.h>

void count(int *total, int *numbers, int size) {
    int _total = 0;

    for (int i = 0; i < size; i++)
        _total += numbers[i];

    printf("%d\n", sizeof(numbers));
    *total = _total;
}

int main() {
    int numbers[] = {2, 5, 1, 2, 20};
    int total = 0;

    count(&total, numbers, 5);
    printf("Total: %d\n", total);
}