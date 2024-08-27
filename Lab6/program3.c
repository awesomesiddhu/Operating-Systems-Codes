//Demo Truncate

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   int fd = -1;

   if (argc != 2) {
      printf("Usage: %s <file>\n", argv[0]);
      exit(1);
   }

   fd = open(argv[1], O_CREAT | O_WRONLY, 0644);
   if (fd == -1) {
      printf("unable to create file\n");
      exit(1);
   }

   for (int i = 0; i < 10; i++)
      write(fd, "test", 4);

   close(fd);

   if (truncate(argv[1], 0) == -1)
      printf("unable to truncate the file\n");

   exit(0);
}
