#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printarr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* remove_element(int* arr, int size, int idx) {
    int* temp = malloc((size - 1) * sizeof(int));

    // copies elements as much as the index (or everything before the target)
    // ex: the target index is 2, then it copies the first 2 elements
    if (idx != 0) {
        memcpy(temp, arr, idx * sizeof(int));
    }

    // copies all elements after the index to the `temp`
    // at this point, the starting point is at index.
    //
    // if you don't know, when you do something like `(arr + 2)`
    // it gets some part of the array, and from the example above
    // the index 0 will start at index 2 (from the original array)
    if (idx != (size - 1)) {
        memcpy((temp + idx), (arr + idx + 1), (size - idx - 1) * sizeof(int));
    }

    free(arr);
    return temp;
}

// 1 2 3 4 5
//     ^
// cpy = 1 2

int main() {
    int size = 5;
    // int* arr = malloc(size * sizeof(int));
    int* arr = calloc(size, sizeof(int));

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    // printf("Test: %d\n", (arr + 3)[0]);
    // printarr(arr, size);

    int idx = 2;
    printf("Index: %d\n", idx);
    printf("Element: %d\n", arr[idx]);
    printf("Test: %d\n", (arr + idx + 1)[0]);

    printf("\n");

    printf("Before: ");
    printarr(arr, size);

    arr = remove_element(arr, size, idx);
    size--;

    printf("After: ");
    printarr(arr, size);

    return 0;
}