#include <stdio.h>
#include <stdlib.h>

int main()
{

    pid_t pids[10];
    int i;
    int n = 10;

    for (i = 0; i < n; ++i) {
        if ((pids[i] = fork()) < 0) {
        perror("fork");
        abort();
        } else if (pids[i] == 0) {
        //child's working
        exit(0);
        }
    }


    int status;
    pid_t pid;
    for(i = 0; i<n; ++i) {
        pid = wait(&status);
        printf("Child with PID %d exited with status %d.\n", pid, status);
    }

    return 0;
}
