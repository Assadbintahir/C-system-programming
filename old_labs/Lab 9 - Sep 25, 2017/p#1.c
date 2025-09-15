#include <stdio.h>
#include <stdlib.h>
#include  <sys/types.h>


int main()
{
     pid_t  pid;

     fork();
     pid = getpid();
     printf("Process id is %d\n", pid);
     return 0;
}
