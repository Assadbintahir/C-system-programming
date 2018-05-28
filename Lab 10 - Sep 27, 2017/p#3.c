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
        printf("pid in child=%d \n",getpid());
        exit(1);


    }
    else{
        printf("pid in parent=%d \n",getpid());

        while(1){
            int a = 1;
        }

    }
    return 0;
}
