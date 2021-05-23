#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    int pid, to[2], from[2];
    if (pipe(to) == -1 || pipe(from) == -1) {
        perror("pipe failed");
        exit(1);
    }
    if ((pid = fork()) == -1) {
        perror("fork failed");
        exit(2);
    }
    if (pid == 0) {
        if (dup2(to[0], 0) == -1) {
            perror("3");
            exit(3);
        }
        close(to[0]);
        close(to[1]);
        if (dup2(from[1], 1) == -1) {
            perror("4");
            exit(4);
        }
        close(from[0]);
        close(from[1]);

        execlp("dc", "dc", "-", NULL);
        perror("5");
        exit(5);
    } else {
        close(to[0]);
        close(from[1]);
        FILE* fpout = fdopen(to[1], "w");
        FILE* fpin = fdopen(from[0], "r");
        //
        fclose(fpout);
        fclose(fpin);
    }
}