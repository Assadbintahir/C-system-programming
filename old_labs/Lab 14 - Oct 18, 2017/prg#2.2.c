#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define NOT_READY -1
#define READY 0
#define GOT 1

struct Memory{
    int status;
    int data[4];
};


int main()
{
    key_t ShmKey;
    int ShmID, i;
    struct Memory *ShmPTR;

    ShmKey = ftok("./",'x');
    ShmID = shmget(ShmKey, sizeof(struct Memory), 0666);
    ShmPTR = (struct Memory *)shmat(ShmID, NULL,0);

    for(i=0; i<10; i++){
        printf("%d\n",ShmPTR->data[i]);
    }

    printf("\nmemory read from %d \n", ShmKey);


    sleep(10);


    printf("\nmemory destroyed\n");


    return 0;
}
