#include <stdio.h>
#include <stdlib.h>
#include  <sys/types.h>

void todo(){
    printf("todo function is called once the child is exited.\n\n");
}

int main()
{
     pid_t pid;
    pid=fork();
    if(pid==-1){
        perror("fork failure");
        exit(EXIT_FAILURE);
    }
    else if(pid==0){
        //this function does the work of onexit function.
        atexit(todo);

        printf("pid in child=%d and parent=%d\n",getpid(),getppid());
        printf("The child exited with return code \n");
        _exit(EXIT_SUCCESS);
    }
    else{
        printf("pid in parent=%d and childid=%d\n",getpid(),pid);
    }




    return 0;
}
