#include<stdio.h>
#include<pthread.h>

pthread_t tid;

void *display(void *data)
{
   // printf("THIS IS THREAD\n");
}

int main()
{
    printf("BEFORE THREAd Create\n");
    pthread_create(&tid,NULL,display,NULL);
    printf("After THREAD\n");

    return 0;
}