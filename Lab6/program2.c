//Demo Get UID

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
   int rv = 0;

   printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());

   if(setuid(0) != 0)
	   printf("error setting uid\n");

   if(setgid(0) != 0)
	   printf("error setting gid\n");

   printf("After setuid(0): real uid = %d, effective uid = %d\n", getuid(), geteuid());

   exit(0);
}

