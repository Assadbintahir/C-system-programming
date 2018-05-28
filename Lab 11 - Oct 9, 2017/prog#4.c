#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void myhandler(int sig)
{
  pid_t pid;
  int status;
  pid = wait(&status);

  printf("process with Pid %d exited.\n", pid);
}

int main(void)
{
  signal(SIGCHLD, myhandler);

  if(!fork())
  {
    printf("Child with pid is %d\n", getpid());
    exit(0);
  }
  printf("Parent with pid is %d\n", getpid());
    //exit(0);
	while(1){
}

  return 0;
}
