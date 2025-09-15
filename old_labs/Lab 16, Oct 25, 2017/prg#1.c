#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    mqd_t mqd;
    struct mq_attr attr;
    mqd = mq_open(argv[1],O_RDONLY | O_CREAT );
    
    if(mqd==-1){
        printf("mq_open error");
        exit(0);
    }
    
    if(mq_getattr(mqd, &attr) == -1){
        printf("get attribute error");
        exit(0);
    }
    
    printf("Maximum # of messages on queue: %ld\n", attr.mq_maxmsg);
    printf("Maximum messages size: %ld\n", attr.mq_msgsize);
    printf("# of message currently on queue: %ld\n", attr.mq_curmsgs);
    exit(0);
}
