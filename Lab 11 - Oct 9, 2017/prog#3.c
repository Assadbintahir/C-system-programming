#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

struct sigaction old_act;

void sigint_handler(int sig_no)
{
    printf("\n\nYou hit ctrl - c\n");
    sigaction(SIGINT, &old_act, NULL);
    kill(0, SIGINT);
}

int main()
{

    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = &sigint_handler;
    sigaction(SIGINT, &act, &old_act);

    pause();

    return 0;
}
