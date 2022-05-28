#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main ()
{
    char str [15];
    int fd;
    fd=open("dac.txt",O_CREAT | O_RDWR);
    if(fd==-1)
    {
        perror("Error opening file\n");
        return -1;
    }

     else
    {
    read(fd, str ,15);
    printf("%s\n",str);
    close(fd);
    return 0;
    }
}