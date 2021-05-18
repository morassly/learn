#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <stdlib.h>
void tty_mode(int);
void set_noecho_mode();
void set_flag();
void ctrl_c_handle(int);
int main() {
    tty_mode(0);
    set_noecho_mode();
    set_flag();
    signal(SIGINT,ctrl_c_handle);
    signal(SIGQUIT,SIG_IGN);
    tty_mode(1);
    return 0;
}
void tty_mode(int how) {
    static int stored = 0;
    static int flags;
    static struct termios mode;
    if (!how) {
        tcgetattr(0, &mode);
        flags = fcntl(0, F_GETFL);
        stored = 1;
    } else if(stored){
        tcsetattr(0,TCSANOW,&mode);
        fcntl(0,F_SETFL,flags);
    }
}
void set_noecho_mode(){
    struct termios ttystate;
    tcgetattr(0,&ttystate);
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_lflag &= ~ECHO;
    ttystate.c_cc[VMIN] = 1;
    tcsetattr(0,TCSANOW,&ttystate);
}
void set_flag(){
    int flags;
    flags = fcntl(0,F_GETFL);
    flags |= O_NDELAY;
    fcntl(0,F_SETFL,flags);
}
void ctrl_c_handle(int sig){
    tty_mode(1);
    exit(1);
}