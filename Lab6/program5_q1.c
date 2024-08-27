//Q1. Write a C program to change the permissions of files in a directory created after a certain date. Inputs to the program: directory, date and new permission to be set as run time arguments

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s directory date permissions\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *directory = argv[1];
    char *date = argv[2];
    mode_t new_permissions = strtol(argv[3], NULL, 8);

    struct stat st;
    struct dirent *dir_entry;
    DIR *dir = opendir(directory);

    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        char file_path[1024];
        sprintf(file_path, "%s/%s", directory, dir_entry->d_name);

        if (stat(file_path, &st) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISREG(st.st_mode) && strcmp(ctime(&st.st_mtime), date) > 0) {
            if (chmod(file_path, new_permissions) == -1) {
                perror("chmod");
            } else {
                printf("Changed permissions of %s\n", file_path);
            }
        }
    }

    closedir(dir);
    return 0;
}
