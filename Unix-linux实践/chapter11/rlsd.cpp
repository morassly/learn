#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#define oops(msg)    \
    {                \
        perror(msg); \
        exit(1);     \
    }
#define PORTNUM 15000
int main(){
    //Step1 get a socket 

    int sock_id = socket(AF_INET,SOCK_STREAM,0);
    if (sock_id == -1)
        oops("socket");

    //Step2 bind address to socket

    struct sockaddr_in servadd;
    char hostname[256];
    bzero(&servadd, sizeof(servadd));
    gethostname(hostname,256);
    struct hostent* hp = gethostbyname(hostname);
    bcopy(hp->h_addr, (struct sockaddr*)&servadd.sin_addr, hp->h_length);
    servadd.sin_family = AF_INET;
    servadd.sin_port = htons(PORTNUM);
    if(bind(sock_id,(struct sockaddr *)&servadd,sizeof(servadd)) != 0)
        oops("bind");
    
    //Step3 listen

    if(listen(sock_id,1) != 0)
        oops("listen");

    //Step4 accept write close

    FILE* fpi,*fpo,*pipe_fp;
    while(true) {
        int sock_fd = accept(sock_id,NULL,NULL);
        if(sock_fd == -1)
            oops("accept");
        if((fpi = fdopen(sock_fd,"r")) == NULL)
            oops("fdopen reading");
        char dirname[256];
        if(fgets(dirname,251,fpi) == NULL)
            oops("reading dirname");
        
        if((fpo = fdopen(sock_fd,"w")) == NULL)
            oops("fdopen writing");
        char command[256];
        sprintf(command,"ls %s",dirname);
        if((pipe_fp = popen(command,"r"))==NULL)
            oops("popen");
        
        int c;
        while((c= getc(pipe_fp)) != EOF)
            putc(c,fpo);
        pclose(pipe_fp);
        fclose(fpi);
        fclose(fpo);
    }

    return 0;
}