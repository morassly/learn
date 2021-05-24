#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define oops(msg)    \
    {                \
        perror(msg); \
        exit(1);     \
    }
#define PORTNUM 15000

int main(int argc, char* argv[]) {
    if (argc != 3) {
        exit(1);
    }

    // Step1 Get a socket

    int sock_id = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_id == -1)
        oops("socket");

    //Step2 connect to server

    struct sockaddr_in servadd;
    bzero(&servadd, sizeof(servadd));
    struct hostent* hp = gethostbyname(argv[1]);
    bcopy(hp->h_addr, (struct sockaddr*)&servadd.sin_addr, hp->h_length);
    servadd.sin_family = AF_INET;
    servadd.sin_port = htons(PORTNUM);
    if (connect(sock_id, (struct sockaddr*)&servadd, sizeof(servadd)) != 0)
        oops("connect");

    //Step3 send dirctiry name,then read back results

    if (write(sock_id,argv[2],strlen(argv[2])) == -1)
        oops("write");
    if (write(sock_id,"\n",1)==-1)
        oops("write");
    
    char buff[10000];
    int n_read;
    while((n_read = read(sock_id,buff,10000)) >0){
        if(write(1,buff,n_read) == -1)
            oops("write");
    }
    close(sock_id);
    
    return 0;
}