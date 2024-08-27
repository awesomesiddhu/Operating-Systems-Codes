//Demo UMASK

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char *argv[])
{
   umask(0); // Set the umask to 0
   
   if (creat(argv[1], RWRWRW) < 0)
      printf("Error creating the file\n");

   exit(0);
}
