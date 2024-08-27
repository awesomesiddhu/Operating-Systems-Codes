#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

sem_t mutex;

void *my_thread_1(void *arg)
{
   char s[] = "abcdefgh";
   int l = strlen(s);

   for(int i = 0; i < l; ++i)
   {
      sem_wait(&mutex);
      putchar(s[i]);
      fflush(stdout); 
      sem_post(&mutex);
      sleep(1);
   }
}

void *my_thread_2(void *arg)
{
   char s[] = "ABCDEFGH";
   int l = strlen(s);

   for(int i = 0; i < l; ++i)
   {
      sem_wait(&mutex);
      putchar(s[i]);
      fflush(stdout); 
      sem_post(&mutex);
      sleep(2);
   }
}

int main()
{
    pthread_t t1, t2;

    sem_init(&mutex, 0, 1);

    pthread_create(&t1, NULL, my_thread_1, NULL);
    pthread_create(&t2, NULL, my_thread_2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    sem_destroy(&mutex);

    printf("\n");    
    return 0;
}