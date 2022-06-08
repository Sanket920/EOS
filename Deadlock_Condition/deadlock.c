#include<stdio.h>
#include<pthread.h>

int count = 0;
pthread_mutex_t mutex_count;

void *inc_thread(void *arg)
{
    while(1)
    {
    printf("Inc: Locking Ist Time\n");
    pthread_mutex_lock(&mutex_count);

    printf("Inc: Locking 2nd Time\n");
    pthread_mutex_lock(&mutex_count);

    printf("Inc: Changing Count");
    count++;
    printf("Inc Thread %d\n",count);

    pthread_mutex_unlock(&mutex_count);
    printf("Inc: Unlocked First Time\n");

    pthread_mutex_unlock(&mutex_count);
    printf("Inc: Unlocked FIrst Time\n");

    }
}

void *dec_thread(void *arg)
{
    while(1)
    {
    printf("Dec: Locking Ist Time\n");
    pthread_mutex_lock(&mutex_count);

    printf("Dec: changing Count\n");
    count--;
    printf("Dec Thread %d\n",count);

    pthread_mutex_unlock(&mutex_count);
    printf("Dec: Unlocked Ist Time\n");

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