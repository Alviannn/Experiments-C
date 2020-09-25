#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    /** the person's name */
    char name[128];
    /** the person's age */
    int age;

    /** creates the person's introduction message */
    char *(*intro)();
} Person;

char *intro(Person person) {
    return "";
}

Person newPerson(char name[], int age) {
    struct Person person;

    strcpy(person.name, name);
    person.age = age;
    person.intro = intro;

    return person;
}

int main() {
    Person person = newPerson("Alvian Daru Quthni", 19);
    int array[40] = {0};

    printf("Size: %d\n", sizeof(array) / sizeof(array[0]));

    int *pArray = array;
    pArray = realloc(pArray, 50 * sizeof(int));

    printf("Size: %d\n", sizeof(array) / sizeof(array[0]));

    return 0;
}