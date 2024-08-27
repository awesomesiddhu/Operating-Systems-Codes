// Program to demonstrate Zombie Process. 
// Child becomes Zombie as parent is sleeping when child process exits.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork(); // Create child process

    if (pid > 0) 
    {
       sleep(5); // Parent process sleeps for 5 seconds
       printf("In parent\n");
    }
    else if (pid == 0)           
    {
       printf("In child\n");
       exit(0); // Child process exits
    }
    return 0;
}
