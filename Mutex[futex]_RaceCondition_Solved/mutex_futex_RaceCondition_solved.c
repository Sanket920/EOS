#include<stdio.h>
#include<pthread.h>

int count = 0;
pthread_mutex_t mutex_count;

void *inc_thread(void *arg)
{
    while(1)
    {

    pthread_mutex_lock(&mutex_count);
    count++;
    printf("Inc Thread %d\n",count);
    pthread_mutex_unlock(&mutex_count);

    }
}

void *dec_thread(void *arg)
{
    while(1)
    {

    pthread_mutex_lock(&mutex_count);
    count--;
    printf("Dec Thread %d\n",count);
    pthread_mutex_unlock(&mutex_count);

    }
}

int main()
{
    pthread_t inc,dec;

    pthread_mutex_init(&mutex_count,NULL);

    pthread_create(&inc,NULL,inc_thread,NULL);
    pthread_create(&dec,NULL,dec_thread,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);

    pthread_mutex_destroy(&mutex_count);
    
    return 0;
}