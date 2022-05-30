#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    
    int fd;
    fd=open("desdinfo",O_WRONLY);
    write(fd,"SANKET\n",7);
    close(fd);
    return 0;
}