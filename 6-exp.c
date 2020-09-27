#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Generates a random number
 */
int random_int(int max, int min) {
    srand(time(NULL));
    return rand() % max + min;
}

int main() {
    int secret_number = random_int(10, 1);
    int guess = 0;

    int max_attempt = 3;
    int attempt = 0;

    while (guess != secret_number) {
        if (attempt >= max_attempt) {
            printf("Failed to guess the number! The answer is %d!\n", secret_number);
            return 0;
        }

        printf("Guess a number between 1 and 10: ");
        scanf("%d", &guess);
        
        attempt++;
    }

    printf("You're correct! The secret number is %d!\n", secret_number);
}