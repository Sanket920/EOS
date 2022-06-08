#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int count = 0;

sem_t sem_count;

void *inc_thread(void *arg)
{
    while(1)
    {
    sem_wait(&sem_count);
    count++;
    printf("Inc Thread %d\n",count);
    sem_post(&sem_count);
    }
}

void *dec_thread(void *arg)
{
    while(1)
    {
    sem_wait(&sem_count);
    count--;
    printf("Dec Thread %d\n",count);
    sem_post(&sem_count);
    }
}

int main()
{
    pthread_t inc,dec;

    sem_init(&sem_count,0,0);    //initialise to 0 means all thread now going to block => waiting state

    pthread_create(&inc,NULL,inc_thread,NULL);
    pthread_create(&dec,NULL,dec_thread,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);

    sem_destroy(&sem_count);
    return 0;
}