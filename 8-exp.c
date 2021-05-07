#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int max, int min) {
    return rand() % (max - min + 1) + min;
}

void generate_str(char* str, int length) {
    int curlen = 0;

    while (curlen < length - 1) {
        // upper chars = 90 - 65
        // lower chars = 122 - 97

        char rand_upper = (char)random(90, 65);
        char rand_lower = (char)random(122, 97);

        char chosen = random(1, 0) ? rand_upper : rand_lower;

        str[curlen] = chosen;
        curlen++;
    }

    str[curlen] = '\0';
}

int main() {
    srand(time(NULL));

    char str[101];
    for (int i = 0; i < 10; i++) {
        generate_str(str, 10);
        printf("Random %2d: %s\n", i + 1, str);
    }

    return 0;
}