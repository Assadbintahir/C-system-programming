#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void sig_handler(int sig)
{
    printf("Handler ran.\n");
    //exit(1);
}
int main()
{
    signal(SIGINT, &sig_handler);
    
    printf("Signal sent to handler \n");
    while(1);

    raise(SIGINT);



    return 0;
}
