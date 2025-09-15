#include <stdio.h>
#include <stdlib.h>
#include  <sys/types.h>



int main()
{
     pid_t pid;
    pid=fork();
    if(pid==-1){
        perror("fork failure");
        exit(EXIT_FAILURE);
    }
    else if(pid==0){
        printf("pid in child=%d and parent=%d\n",getpid(),getppid());
        printf("The child exited with return code \n");
        exit(EXIT_SUCCESS);
    }
    else{
        printf("pid in parent=%d and childid=%d\n",getpid(),pid);
    }

    


    return 0;
}
