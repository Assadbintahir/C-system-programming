#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int p[2], pid;
    char buf[64];
    
    if(pipe(p) == -1){
        perror("pipe call");
        exit(1);
    }
    
    if(fork() == 0){
        write(p[1], "IBA", 3);
        printf("In parent writing\n");
    }
    else {
       read(p[0], buf, 9);
        printf("In child reading: %s\n", buf); 
    }
    
    
    
    
    return 0;
    
    
}
