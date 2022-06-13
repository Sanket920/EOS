#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

#define MSG_SIZE 128
struct mq_attr attr;
mqd_t mqd;

int main()
{
    attr.mq_maxmsg = 4;
    attr.mq_msgsize = MSG_SIZE;
    attr.mq_curmsgs = 0;
    attr.mq_flags = 0;

    mqd = mq_open("/desdmq",O_CREAT | O_RDWR,S_IRUSR |S_IWUSR|S_IWGRP |S_IRGRP, &attr);

    if (-1 == mqd)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    mq_send(mqd, "DESD\n", 5,0);

    mq_close(mqd);
    return 0;

}