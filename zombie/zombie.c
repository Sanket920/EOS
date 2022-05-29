#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{   pid_t id;
    id = fork ();

    if (0 == id)
    {
        printf("child process ID %d PPID %d\n",getpid(),getppid());
        printf("child completed\n");
    }
    else if (0 < id)
    {
        printf("parent process ID %d PPID %d\n",getpid(),getppid());
        sleep(10);
        printf("parent completed\n");
    }
    else
    {
        perror("fork faild\n");
    }
    return 0;
    }