#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>i
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 8192

int main(int argv[], char *argc[])
{
    int size;
    FILE fdr,fdw;
    size_t rd,wr;
    unsigned char buff[MAX_SIZE];

    fpr=open(argc[1],"r");
    if(fpr==NULL)
    {
        perror("Error opening Source file\n");
        return -1;
    }
    fdw=open(argc[2], "w");
    if(fpw==0)
    {
        perror("Error opening Destinaton file\n");
        return -1;
    }
    size =atoi(argc[1]);
    if (size > MAX_SIZE)
    {
        perror("File size exceeded\n");
        return -1;
    }
    while(1)
    {
        rd=fread(buff,1,MAX_SIZE,fpr);
        
        if (rd ==EOF)
        {
            break;
        }
        wr=write(buff,1,rd,fpw); 

        if (wr == 0)
        {
            break;
        }  
    }
    close(fpr);
    close(fpw);
    printf("Copied data into %s\n", argc[2]);
    return 0;
}