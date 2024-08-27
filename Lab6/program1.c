//Demo File Access

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   int fd;

   if (argc != 2) {
      printf("Usage: %s <file>\n", argv[0]);
      exit(1);
   }

   if ((fd = open(argv[1], O_RDONLY)) == -1)
      printf("invalid file\n");

   if (access(argv[1], R_OK) == -1)
      printf("read access error for %s\n", argv[1]);
   else
      printf("read access OK\n");

   if (access(argv[1], W_OK) == -1)
      printf("write access error for %s\n", argv[1]);
   else
      printf("write access OK\n");

   if (access(argv[1], X_OK) == -1)
      printf("exec access error for %s\n", argv[1]);
   else
      printf("exec access OK\n");

   if (fd == -1)
      printf("open error for %s\n", argv[1]);
   else
      printf("opened for reading\n");

   close(fd);
   exit(0);
}