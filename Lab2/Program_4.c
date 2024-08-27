// program to demonstrate creation of child and grandchild processes using fork() and wait() 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t p1, p2;

    int y = 0;

    p1 = fork(); // Create child

    if (p1 > 0) 
    {
        wait(NULL); // Wait for child to finish

        printf("This is parent. Process Id = %d\n", getpid());
    }
    else if (p1 == 0) 
    {
        p2 = fork(); // Create grandchild

        if (p2 > 0)
        {
           wait(NULL); // Wait for grandchild to finish
        }
        else if (p2 == 0)
        {
           printf("This is grandchild. Process Id = %d, Parent Process Id = %d\n", getpid(), getppid());
           exit(0);
        }

        printf("This is child. Process Id = %d, Parent Process Id = %d\n", getpid(), getppid());
        exit(0);
    }
    else 
    {
        printf("fork creation failed!!!\n");
    }
}
