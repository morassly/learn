#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

}
FILE *my_popen(const char* command,const char* mode){
    int p[2],pid;
    int pa,ch;
    if(*mode == 'r'){
        pa = 0;
        ch = 1;
    } else if(*mode == 'w'){
        pa = 1;
        ch = 0;
    } else {
        return NULL;
    }
    pipe(p);
    pid = fork();
    if (pid > 0){
        close(p[ch]);
        return fdopen(p[pa],mode);
    }
    close(p[pa]);
    dup2(p[ch],ch);
    close(p[ch]);
    execl("/bin/sh","sh","-c",command,NULL);
    exit(1);
}