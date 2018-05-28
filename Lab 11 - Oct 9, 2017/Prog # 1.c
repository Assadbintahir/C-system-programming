#include  <stdio.h>
#include  <signal.h>
#include  <stdlib.h>

void handler(int);

int main(void)
{
    signal(SIGINT, handler);
    

    return 0;
}

void  handler(int sig)
{
    char alpha;

    printf("\nyou hit Ctrl-C\n");
    
    printf("do you want to exit?");
    
    scanf("%s", &alpha);
    if(alpha=='y'){
        
    exit(0);
        
    }
    
    
    signal(SIGINT, handler);
    getchar(); // Get new line character
}
