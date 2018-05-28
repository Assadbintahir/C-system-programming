#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void sig_handler(int sig)
{
    printf("signal in child process \n");
    exit(1);
}
int main()
{
    pid_t pid;
    int child_status;
    pid=fork();
    if(pid==0)
    {
        signal(SIGUSR1,&sig_handler);
        printf("CP is waiting for signal \n");
        while(1);
    }
    else
    {
        sleep(3);
        printf("Parent signaled cp \n");
        kill(pid,SIGUSR1);
        wait(&child_status);
        printf("Got exit status of cp \n");
    }
    return 0;
}
