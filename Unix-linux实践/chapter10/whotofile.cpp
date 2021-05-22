#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>  //wait
#include <unistd.h>    //fork

int main(int argc, char *argv[]) {
    int pid = fork();

    if (pid == 0) {
        close(1);
        creat("test.c", 0755);
        execlp("who", "who", NULL);
        exit(1);

    } else {
        wait(NULL);
        printf("done\n");
    }

    return 0;
}