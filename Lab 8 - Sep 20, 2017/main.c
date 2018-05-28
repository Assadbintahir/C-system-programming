#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Program#1

    //time_t curr_time;
    //curr_time = time(NULL);

    //printf("time(NULL) returned %d\n\n", curr_time);
    //puts(ctime(&curr_time));



    //Program#2
    /*
    time_t begin, end;
    long i;
    begin = time(NULL);

    for(i=0;i<290000000;i++);

    end = time(NULL);

    printf("for loops take %f seconds\n",difftime(end,begin));
    */


    //Program#3

    clock_t c1 = clock();
    long i;

    for(i=0;i<290000000;i++);

    clock_t c2 = clock();

    printf("for loops take %f ticks\n",difftime(c2,c1));



    return 0;
}
