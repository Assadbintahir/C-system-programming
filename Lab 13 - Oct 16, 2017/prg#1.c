#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <signal.h>


#define SHMOBJ_PATH         "/shmjeshu"


struct shared_data {
    int var1;
    int var2;
};

void signal_callback_handler(int signum)
{

        if ( shm_unlink("/mysem") < 0 )
        {
                perror("shm_unlink");
        }

   exit(signum);
}


int main(int argc, char *argv[]) {
    int shmfd;
    int vol, cur;
    int shared_seg_size = (1 * sizeof(struct shared_data));   
    struct shared_data *shared_msg;      

    signal(SIGINT, signal_callback_handler);

    shmfd = shm_open(SHMOBJ_PATH, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);


    fprintf(stderr, "Created shared memory object %s\n", SHMOBJ_PATH);

    ftruncate(shmfd, shared_seg_size);

    shared_msg = (struct shared_data *)mmap(NULL, shared_seg_size, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);

    fprintf(stderr, "Shared memory segment allocated correctly (%d bytes).\n", shared_seg_size);

    vol = 10;
    cur = 0;
    while(1)
    {
        shared_msg->var1 = vol;
        shared_msg->var2 = cur;
        sleep(3);
        vol++;
        cur++;
    }


    return 0;
}
