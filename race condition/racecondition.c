#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

     
int count = 0;

void *incThread(void *arg)
{
    while(1)
    {
        printf("inc Thread %d\n",count);
        count++;

    }
}
void *decThread(void *arg)
{
    while(1)
    {
        printf("dec Thread %d\n",count);
        count--;

    }
}
int main(int argc, char const *argv[])
{
    pthread_t inc, dec;
    pthread_create(&inc,NULL,incThread,NULL);
    pthread_create(&dec,NULL,decThread,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);
    return 0;
}
