#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
int make_internet_address(char* hostname, int port, struct sockaddr_in* addr);
int make_dgram_server_socket(int portnum) {
    //Step 1;
    int sock_id = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock_id == -1)
        return -1;

    struct sockaddr_in servadd;
    char hostname[256];
    gethostname(hostname, 256);
    make_internet_address(hostname, portnum, &servadd);
    if (bind(sock_id, (struct sockaddr*)&servadd, sizeof(servadd)) != 0)
        return -1;
    return sock_id;
}

int make_dgram_client_socket() {
    return socket(PF_INET, SOCK_DGRAM, 0);
}

int make_internet_address(char* hostname, int port, struct sockaddr_in* addr) {
    bzero(addr, sizeof(struct sockaddr_in));
    struct hostent* hp = gethostbyname(hostname);
    if (hp == NULL) return -1;
    bcopy(hp->h_addr, (struct sockaddr*)&addr->sin_addr, hp->h_length);
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    return 0;
}

int get_internet_address(char* host, int len, int* port, struct sockaddr_in* addr) {
    strncpy(host, inet_ntoa(addr->sin_addr), len);
    *port = ntohs(addr->sin_port);
    return 0;
}