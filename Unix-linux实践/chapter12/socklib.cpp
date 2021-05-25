#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int make_server_q(int, int);
int make_server(int portnum) {
    return make_server_q(portnum, 1);
}

int make_server_q(int portnum, int backlog) {
    int sock_id = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_id == -1)
        return -1;

    //Step2 bind address to socket

    struct sockaddr_in servadd;
    char hostname[256];
    bzero(&servadd, sizeof(servadd));
    gethostname(hostname, 256);
    struct hostent* hp = gethostbyname(hostname);
    bcopy(hp->h_addr, (struct sockaddr*)&servadd.sin_addr, hp->h_length);
    servadd.sin_family = AF_INET;
    servadd.sin_port = htons(portnum);
    if (bind(sock_id, (struct sockaddr*)&servadd, sizeof(servadd)) != 0)
        return -1;

    //Step3 listen

    if (listen(sock_id, 1) != 0)
        return -1;
    return sock_id;
}

int connect_to_server(char* host,int portnum){
    int sock_id = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_id == -1)
        return -1;

    //Step2 connect to server

    struct sockaddr_in servadd;
    bzero(&servadd, sizeof(servadd));
    struct hostent* hp = gethostbyname(host);
    bcopy(hp->h_addr, (struct sockaddr*)&servadd.sin_addr, hp->h_length);
    servadd.sin_family = AF_INET;
    servadd.sin_port = htons(portnum);
    if (connect(sock_id, (struct sockaddr*)&servadd, sizeof(servadd)) != 0)
        return -1;
    return sock_id;   
}