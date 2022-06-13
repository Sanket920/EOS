#include<stdio.h>
#include<stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>       
#include <fcntl.h>   
#include<unistd.h>
#include<sys/types.h>


int *count = NULL;

int main()
{
 int shmfd;
 shmfd = shm_open("/desdshm",O_CREAT|O_RDWR,S_IWUSR|S_IRGRP|S_IWGRP);

 if (-1 == shmfd)
{
    perror("shm_open");
    return EXIT_FAILURE;
}
ftruncate(shmfd, sizeof(int));
 count = (int *)mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE,MAP_SHARED, shmfd,0);

 while (1)
 {
    *count = *count + 1;
    sleep(1);
 }
 return 0;

}