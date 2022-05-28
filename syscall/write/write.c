#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main ()
{
    int fd;
    fd=open("dac.txt",O_CREAT | O_WRONLY);
    if(fd==-1)
    {
        perror("Error opening file\n");
        return -1;
    }

     else
    {
    write(fd,"cdac hyderabad\n",15);
    close(fd);
    return 0;
    }
}