#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int child_status;

    pid=fork();
    if(pid==-1){
        perror("fork failure");
        exit(EXIT_FAILURE);
    }
    else if(pid==0){
        printf("pid in child=%d and parent=%d\n",getpid(),getppid());
        exit(5);


    }
    else{
        printf("pid in parent=%d and childid=%d\n",getpid(),pid);

        int child_id = wait(&child_status);

        printf("wait_id is %d and child ID is: %d\n", WEXITSTATUS(child_status), child_id);

    }
    return 0;
}
