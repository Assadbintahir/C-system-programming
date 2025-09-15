

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler()
{
  signal(SIGALRM, &handler);
    printf("received SIGALARM\n");
	alarm(1);
}

int main(void)
{
  signal(SIGALRM, &handler);
  	alarm(1);
    while(1)
    sleep(1);
  return 0;
}
