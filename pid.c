#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    printf("ID = %d\n",getpid());
    printf("Parent process ID = %d\n",getppid());
    return 0;
}

