#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR* dir = opendir(".");

    struct dirent* file;
    while ((file = readdir(dir)) != NULL) {
        printf("file: %s\n", file->d_name);

        struct stat temp;

        int res = stat(file->d_name, &temp);
        printf("STAT: %d %d ", temp.st_mode, res);

        if (S_ISDIR(temp.st_mode)) {
            printf("IS DIRECTORY");
        } else {
            printf("NOT DIRECTORY DIRECTORY");
        }

        printf("\n\n");
    }

    closedir(dir);
    return 0;
}