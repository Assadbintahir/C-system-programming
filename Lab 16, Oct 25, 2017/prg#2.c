#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    mqd_t mqd;
    struct mq_attr attr;
    unsigned int prio;
    mqd = mq_open(argv[1],O_EXCL | O_RDWR | O_CREAT );
    
    if(mqd==-1){
        printf("mq_open error");
        exit(0);
    }
    
    for (prio = 0; prio <= 100; prio += 8) {
    printf ("Writing a message with priority %d.\n", prio);    
    if (mq_send (mqd, "I8-)", 4, prio) == -1)
      perror ("mq_send()");
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
