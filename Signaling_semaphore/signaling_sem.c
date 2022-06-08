#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int a,b;

sem_t sem_ip_to_pr,sem_pr_to_ip;

void *inputThread(void *data)
{
    while(1)
    {
        sem_wait(&sem_pr_to_ip);
        printf("\nEnter The Value Of a And b: \n");
        scanf("%d",&a);
        scanf("%d",&b);   
        sem_post(&sem_ip_to_pr);
    }
}

void *processingThread(void *data)
{
    int sum=0;
    while(1)
    {
        sem_wait(&sem_ip_to_pr);
        sum=a+b;
        printf("Sum Of a And b : %d\n",sum);
        sem_post(&sem_pr_to_ip);
    }
}

int main()
{
    pthread_t inputTid,processingTid;

    sem_init(&sem_pr_to_ip,0,1);
    sem_init(&sem_ip_to_pr,0,0);

    pthread_create(&inputTid,NULL,inputThread,NULL);
    pthread_create(&processingTid,NULL,processingThread,NULL);

    pthread_join(inputTid,NULL);
    pthread_join(processingTid,NULL);

    sem_destroy(&sem_ip_to_pr);
    sem_destroy(&sem_pr_to_ip);

    return 0;
}