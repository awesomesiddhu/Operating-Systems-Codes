#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    int pipefd[2];
    pid_t pid;
    char inputStr[BUFFER_SIZE];
    char reversedStr[BUFFER_SIZE];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process reads from pipe and reverses the string
        close(pipefd[1]); // Close write end of the pipe

        ssize_t bytesRead = read(pipefd[0], inputStr, sizeof(inputStr));
        if (bytesRead == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        inputStr[bytesRead] = '\0'; // Null terminate the string

        // Reverse the string
        reverseString(inputStr);

        printf("Reversed string: %s\n", inputStr);

        close(pipefd[0]); // Close read end of the pipe in child process
        exit(EXIT_SUCCESS);
    } else { // Parent process takes input, writes to pipe, then waits for child
        close(pipefd[0]); // Close read end of the pipe

        printf("Enter a string: ");
        fgets(inputStr, BUFFER_SIZE, stdin);

        ssize_t bytesWritten = write(pipefd[1], inputStr, strlen(inputStr));
        if (bytesWritten == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(pipefd[1]); // Close write end of the pipe in parent process

        wait(NULL); // Wait for the child process to finish
    }

    return 0;
}
