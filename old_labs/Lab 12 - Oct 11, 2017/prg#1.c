#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sigint_handler(int signo)
{
  if (signo == SIGINT)
    printf("received SIGINT\n");
}

void sigterm_handler(int signo)
{
  if (signo == SIGTERM)
    printf("received SIGTERM\n");
}

int main(void)
{
  if (signal(SIGINT, sigint_handler) == SIG_ERR)
    printf("\ncan't catch SIGINT\n");

    printf("process id is %d \n",getpid());

  if (signal(SIGTERM, sigterm_handler) == SIG_ERR)
    printf("\ncan't catch SIGTERM\n");

  // A long long wait so that we can easily issue a signal to this process
  while(1)
    sleep(1);
  return 0;
}
