#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Replaces a part of the string with a new replacement
 * 
 * @param org     the original string
 * @param target  the targetted part of the string
 * @param replace the replacement
 */
char *replacestr(char *org, char target[], char replace[]) {
    // TODO: check if string is valid

    // prepares all string sizes
    register int org_size = strlen(org) + 1;
    register int replace_size = strlen(replace) + 1;
    register int target_size = strlen(target) + 1;

    // the counter to know how much the targetted string matches the string
    register int match_counter = 0;
    // the index where the replacement should start at
    register int starting_index = -1;
    // the final result of the string (already replaced)
    char *result;

    // determines the similarities or equalities
    for (int i = 0; i < org_size; i++) {
        char part_org = org[i];
        char part_target = replace[0];

        // don't continue if the match counter surpasses the target of replacement size
        if (match_counter >= target_size)
            break;

        // if both parts of original and the target of the replacement matches then start counting
        // and saves the starting index if previously isn't saved
        // otherwise resets the counter and the starting index
        if (part_org == part_target) {
            match_counter++;
            if (starting_index == -1)
                starting_index = i;
        } else {
            match_counter = 0;
            starting_index = -1;
        }
    }

    // final determination whether the target replacement matches anything
    // from the original string
    if (match_counter < target_size || starting_index == -1)
        return org;

    return NULL;
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

/**
 * Inserts a string into an original string
 * 
 * @param org    the original string
 * @param index  the insertion index
 * @param insert the string to be inserted
 */
char *insertstr(char *org, int index, char *insert) {
    int insert_size = strlen(insert);
    int org_size = strlen(org) + 1;
    // saves the index location of the last inserted index
    int last_insert = 0;

    char *result = malloc((org_size + insert_size) * sizeof(int));

    // determines if the insertion can be executed
    if (org_size < 1 || index >= org_size || index < 0)
        return org;

    // copies the string before the insertion takes place
    // to the result variable
    for (int i = 0; i <= index; i++)
        result[i] = org[i];

    // starts inserting the supposed inserted string
    for (int i = 0; i < insert_size; i++) {
        last_insert = index + i;
        result[last_insert] = insert[i];
    }

    // copies the remaining original strings
    for (int i = last_insert; i < org_size; i++)
        result[i + 1] = org[index + i - 1];

    return result;
}

int main() {
    printf("\n");

    char *original = "Hello! My name is Alvian and I'm 19 years old!";
    printf("Original : %s\n", original);

    char *result = insertstr(original, 5, "Blabla");
    printf("Inserted : '%s'\n", result);

    // expected results: HelloBlabla My name is Alvian and I'm 19 years old

    printf("\n");

    return 0;
}