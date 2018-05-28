#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

struct sigaction act;

void sighandler(int sig)
{
    printf("Signal handler ran");
}

int main()
{

    struct sigaction setup_action;
    sigset_t set;

    printf("PID of process is %lu \n", (unsigned long)getpid());

    sigemptyset(&set);

    sigaddset(&set, SIGINT);

    setup_action.sa_handler = sighandler;
    setup_action.sa_mask = set;
    setup_action.sa_flags = 0;


    // Waiting for CTRL+C...
    sleep(100);

    return 0;
}
