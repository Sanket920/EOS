#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#define MAX_BUFF_SIZE 5
int main()
{
    unsigned char buff[MAX_BUFF_SIZE];
    //unsigned char P_buff[MAX_BUFF_SIZE];
    pid_t id;
    int fd[2];

    pipe(fd);

    id=fork();
    if(id==0)
    {
        close(fd[1]);
        printf("Child Process\n");
        read(fd[0],&buff,sizeof(buff));
        printf("Child Process Data Received BY Parent:: %s\n",buff);
    }
    else
    {
        close(fd[0]);
        printf("Parent Process\n");
      //  P_buff[MAX_BUFF_SIZE] = "DESD\n";
        write(fd[1],"DESD\n",sizeof(buff));
      //  printf("Parent Process Data %s\n",P_buff);
    }
    return 0;
}
