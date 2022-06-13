#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int a,b;

sem_t sem_2,sem_1;

void *inputThread(void *data)
{
    while(1)
    {
        sem_wait(&sem_1);
        printf("\nEnter The Value Of a And b: \n");
        scanf("%d",&a);
        scanf("%d",&b);   
        sem_post(&sem_2);
        sem_post(&sem_2);

    }
}

void *processingThread(void *data)
{
    int sum=0;
    while(1)
    {
        sem_wait(&sem_2);
        sem_wait(&sem_2);
        sum=a+b;
        printf("Sum Of a And b : %d\n",sum);
        sem_post(&sem_1);
       
    }
}

int main()
{
    pthread_t inputTid,processingTid;

    sem_init(&sem_1,0,1);
    sem_init(&sem_2,0,1);

    pthread_create(&inputTid,NULL,inputThread,NULL);
    pthread_create(&processingTid,NULL,processingThread,NULL);

    pthread_join(inputTid,NULL);
    pthread_join(processingTid,NULL);

    sem_destroy(&sem_2);
    sem_destroy(&sem_1);

    return 0;
}