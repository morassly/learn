#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <utmp.h>

void show_info(struct utmp*);
int main(int argc, char** agrv) {
    struct utmp utmpbuf;
    int utmpfd;
    int len = sizeof(utmpbuf);
    if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) {
        perror(UTMP_FILE);
        exit(1);
    }

    while (read(utmpfd, &utmpbuf, len) == len) {
        show_info(&utmpbuf);
    }
    close(utmpfd);
    return 0;
}

void show_info(struct utmp* buf) {
    if (buf->ut_type != USER_PROCESS)
        return;
    printf("%-8.8s", buf->ut_name);
    printf(" ");
    printf("%-8.8s", buf->ut_line);
    printf(" ");
    char* cp;
    cp = ctime(&buf->ut_time);
    printf("%12.12s\n", cp + 4);
}