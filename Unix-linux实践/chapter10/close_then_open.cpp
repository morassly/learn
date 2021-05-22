#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd;
    char line[100];
    fgets(line,100,stdin);
    printf("%s\n",line);

    close(0);
    fd = open("/etc/passwd",O_RDONLY);
    if (fd != 0) {
        fprintf(stderr,"could not open data as fd 0\n");
        exit(1);
    }
    fgets(line,100,stdin);
    printf("%s\n",line);
    return 0;
}