#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    unsigned char buff[7];
    int fd;
    fd=open("desdinfo",O_RDONLY);
    read(fd,buff,7);
    printf("READ Data :%s\n",buff);
    close(fd);
    return 0;
}