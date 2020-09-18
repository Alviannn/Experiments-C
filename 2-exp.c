#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
    /** the person's name */
    char name[128];
    /** the person's age */
    int age;

    /** creates the person's introduction message */
    char *(*intro)();
} Person;

char *intro(Person person)
{
    return "";
}

Person newPerson(char name[], int age)
{
    struct Person person;

    strcpy(person.name, name);
    person.age = age;

    return person;
}

/**
 * Replaces a part of the string with a new replacement
 * 
 * @param org     the original string
 * @param target  the targetted part of the string
 * @param replace the replacement
 */
char *replace_string(char *org, char *target, char *replace)
{
    // TODO: check if string is valid

    // prepares all string sizes
    register int org_size = strlen(org);
    register int replace_size = strlen(replace);
    register int target_size = strlen(target);

    // the counter to know how much the targetted string matches the string
    register int match_counter = 0;
    // the index where the replacement should start at
    register int starting_index = -1;
    // the final result of the string (already replaced)
    char *result;

    // determines the similarities or equalities
    for (register int i = 0; i < org_size; i++)
    {
        char part_org = org[i];
        char part_target = replace[0];

        // don't continue if the match counter surpasses the target of replacement size
        if (match_counter >= target_size)
            break;

        // if both parts of original and the target of the replacement matches then start counting
        // and saves the starting index if previously isn't saved
        // otherwise resets the counter and the starting index
        if (part_org == part_target)
        {
            match_counter++;
            if (starting_index == -1)
                starting_index = i;
        }
        else
        {
            match_counter = 0;
            starting_index = -1;
        }
    }

    // final determination whether the target replacement matches anything
    // from the original string
    if (match_counter < target_size || starting_index == -1)
        return org;

    // TODO: continue to replace the string
    //
    // Plan 1:
    //  - deletes the targetted string
    //  - adds the replacement string
    //  - string replacement ends
    //
    // Plan 2:
    // - straight up replacing and then inserting
    // - string replacement ends
    //
    // Question:
    // 1. How to insert a value to an array?
}

int main()
{
    // Person person = newPerson("Alvian Daru Quthni", 19);

    // char *result = replace_string("Hello there! My name is Alviann!", "My name is", "Ore no namae wa");
    // printf("%s", result);

    int array[40] = {0};

    printf("Size: %d\n", sizeof(array) / sizeof(array[0]));

    int *pArray = array;
    pArray = realloc(pArray, 50 * sizeof(int));

    printf("Size: %d\n", sizeof(array) / sizeof(array[0]));

    return 0;
}