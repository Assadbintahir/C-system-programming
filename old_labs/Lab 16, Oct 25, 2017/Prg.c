
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define SERVER_QUEUE_NAME   "/sp-example-server"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

int main (int argc, char **argv)
{
    char message [64];
    
    mqd_t qd_server;   // queue descriptors
    long token_number = 1; 

    printf ("Hey I am working!\n");

    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    if ((qd_server = mq_open (SERVER_QUEUE_NAME, O_RDWR | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror ("mq_open (server)");
        exit (1);
    }
    char in_buffer [MSG_BUFFER_SIZE];
    char out_buffer [MSG_BUFFER_SIZE];

    while (1) {
        

        printf ("Send the token to queue (Press <ENTER>): ");
        
        char temp_buf [10];
        sprintf (message, "/my message-%d", token_number);

            if (fgets (temp_buf, 2, stdin)) {

                // send message queue
                if (mq_send (qd_server, message, strlen (message), 0) == -1) {
                    perror (" Not able to send message to queue");
                    continue;
                }
            }
        
        printf ("Sent the token\n\n");
        sleep(1);
        
        if (mq_receive (qd_server, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
            perror ("mq_receive\n\n");
            exit (1);
        }

        printf ("message received. %s\n\n", in_buffer);

            
        token_number++;
    }
}
