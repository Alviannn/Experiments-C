#include <stdio.h>

void check_chars() {
    char up_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char low_chars[] = "abcdefghijklmnopqrstuvwxyz";

    int size = (sizeof(up_chars) / sizeof(up_chars[0])) - 1;

    for (int i = 0; i < size; i++)
        printf("%c - %d\n", low_chars[i], low_chars[i]);
    printf("\n");

    for (int i = 0; i < size; i++)
        printf("%c - %d\n", up_chars[i], up_chars[i]);
    printf("\n");
}

int main() {
    check_chars();
    return 0;
}