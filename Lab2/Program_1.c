#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t p1;

    int y = 0;

    p1 = fork(); //Create Child

    if (p1 > 0) //Check if it is parent process
    {
        y = y - 1;

        printf("This is parent. Process Id = %d, y = %d\n", getpid(), y);
    }
    else if (p1 == 0) // Check if it is child process 
    {
        y = y + 1;

        printf("This is child. Process Id = %d, Parent Process Id = %d, y = %d\n", getpid(), getppid(), y);
    }
    else //fork failed
    {
        printf("Fork failed!\n");
        return 1;
    }

    return 0;
}
