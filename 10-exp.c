#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char** names;
    int len;
    size_t cursize;
} filelist_t;

filelist_t* listdir(char path[]) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return NULL;
    }

    filelist_t* list = malloc(sizeof(filelist_t));

    list->len = 0;
    list->names = NULL;
    list->cursize = 0;

    struct dirent* temp;
    while ((temp = readdir(dir)) != NULL) {
        // ignore default dirs
        if (strcmp(temp->d_name, ".") == 0 || strcmp(temp->d_name, "..") == 0) {
            continue;
        }

        list->len++;
        int count = list->len;

        list->cursize += sizeof(char*);
        list->names = realloc(list->names, list->cursize);
        list->names[count - 1] = malloc(temp->d_namlen * sizeof(char));

        strcpy(list->names[count - 1], temp->d_name);
    }

    closedir(dir);
    return list;
}

void cleanlistdir(filelist_t* src) {
    for (int i = 0; i < src->len; i++) {
        free(src->names[i]);
    }
    free(src);
}

int main() {
    filelist_t* files = listdir(".");

    if (files == NULL) {
        printf("Cannot open dir!\n");
        return 0;
    }

    printf("Length: %d\n", files->len);
    printf("Files:\n");

    size_t memsize = 0;
    for (int i = 0; i < files->len; i++) {
        char* temp = files->names[i];
        printf("%2d - %s\n", i + 1, temp);

        memsize += (strlen(temp) * sizeof(char));
    }

    printf(
        "\n"
        "Memory size:\n"
        " * Struct: %lld B\n"
        " * Stored string: %lld B\n\n",
        sizeof(files), memsize);

    cleanlistdir(files);
    printf("Successfully cleaned the memory!\n\n");
    return 0;
}