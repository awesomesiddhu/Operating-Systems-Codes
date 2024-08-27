//Q2. Write a C program to truncate the files in a directory created after a certain Date to half its original size. Inputs to the program: directory and date as run time arguments 

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s directory date\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *directory = argv[1];
    char *date = argv[2];

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
            off_t original_size = st.st_size;
            off_t new_size = original_size / 2;

            if (truncate(file_path, new_size) == -1) {
                perror("truncate");
            } else {
                printf("Truncated %s to half its original size\n", file_path);
            }
        }
    }

    closedir(dir);
    return 0;
}
