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
    ShmID = shmget(ShmKey, sizeof(struct Memory), IPC_CREAT | 0666);
    ShmPTR = (struct Memory *)shmat(ShmID, NULL,0);
    ShmPTR->status = NOT_READY;

    for(i=0; i<10; i++){
        ShmPTR->data[i]=i*3;
        printf("%d\n",ShmPTR->data[i]);
    }

    printf("\nmemory created with key %d\n", ShmKey);


    sleep(50);

    shmdt((void *) ShmPTR);
    shmctl(ShmID, IPC_RMID, NULL);

    printf("\nmemory destroyed\n");


    return 0;
}
