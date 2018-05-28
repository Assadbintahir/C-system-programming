#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>


int tcpClient(){
    printf("Starting the TCP Client");

    int sockfd;
    struct sockaddr_in servaddr;
    char sendline[1024], recvline[1024];

    //File parameters
    static const char filename[] = "Data_files/nmea-sample";
    FILE *fptr;

    /*Create TCP socket*/
     if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) <0) {
        perror("Problem in creating the socket");
        exit(2);
     }

    /*Configure settings in address struct*/

    servaddr.sin_family = AF_INET;
    servaddr.sin_port =  htons(8808); //convert to big-endian order
    servaddr.sin_addr.s_addr= inet_addr("127.0.0.1");
    memset(&servaddr, 0, sizeof(servaddr));



    //Connection of the client to the socket
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr))<0) {
        perror("Problem in connecting to the server");
        exit(3);
    }

    //Opening the file
    if ((fptr = fopen(filename, "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // reads one line until EOF reaches
    while (fgets(sendline, sizeof sendline, fptr) != NULL){
        //fputs(sendline, stdout);

        printf("Sending line to OpenCPN: %s\n",sendline);
        //nBytes = strlen(buffer) + 1;
        /*Send message to server*/
        send(sockfd, sendline, strlen(sendline)+1,0);

        //Going to sleep for 100 mili seconds
        usleep(1000);

        if (recv(sockfd, recvline, 1024,0) == 0){
            //error: server terminated prematurely
            perror("The server terminated prematurely");
            exit(4);
        }
        printf("String received from the server: %s\n", recvline);





    }

    printf("Input stream ended\n");
    printf("Closing the file & process here\n");
    fclose(fptr);
}


int udpClient(){
    printf("Starting the UDP client");

    int clientSocket, portNum, nBytes;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    //File parameters
    static const char filename[] = "Data_files/nmea-sample";
    FILE *fptr;

    /*Create UDP socket*/
    clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

    /*Configure settings in address struct*/
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9909);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    /*Initialize size variable to be used later on*/
    addr_size = sizeof serverAddr;



    //Opening the file
    if ((fptr = fopen(filename, "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // reads one line until EOF reaches
    while (fgets(buffer, sizeof buffer, fptr) != NULL){
        fputs(buffer, stdout);

        printf("Sending line to OpenCPN: %s",buffer);
        nBytes = strlen(buffer) + 1;
        /*Send message to server*/
        sendto(clientSocket,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);
        //Going to sleep for 100 mili seconds
        usleep(1000);


    }

    printf("Input stream ended\n");
    printf("Closing the file & process here\n");
    fclose(fptr);
}

//main starts here
int main()
{

    int userChoice;

    //taking input from user
    printf("Enter 1 for UDP or 2 for TCP \n");
    scanf("%d", &userChoice);

    //calling the respective client code.
    if(userChoice == 1){
        udpClient();
    } else if(userChoice == 2){
        tcpClient();
    } else {
        printf("You can only choose TCP or UDP. Closing the program\n");
    }

    return 0;
}


