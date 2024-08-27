// Program to demonstrate Orphan Process.
// Parent process finishes execution while the child process is running. The child process becomes orphan.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if (pid > 0) 
    {
	printf("In parent process process id = %d\n", getpid());
	exit(0); // Parent process finishes execution
    }
    else if (pid == 0) 
    {
	sleep(1); // Sleep to ensure parent process finishes execution
	printf("In child process. process id = %d, parent process id = %d\n", getpid(), getppid());
    }
    return 0;
}
