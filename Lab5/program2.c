// Program to list files and sub-directories of a directory recursively in tree structure.

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

void tree(char *basePath, int root);

int main(int argc, char *argv[])
{
    tree(argv[1], 0);

    return 0;
}

void tree(char *basePath, int root)
{
    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            for (i = 0; i < root; i++) 
            {
                if (i == root - 1)
                    printf("  |_");
                else
                    printf("     ");
            }

            printf("%s\n", dp->d_name);

            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            tree(path, root + 1);
        }
    }

    closedir(dir);
}
