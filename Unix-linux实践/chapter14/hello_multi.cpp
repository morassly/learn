#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void * print_msg(void*);
int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,print_msg,(void *)"hello");
    pthread_create(&t2,NULL,print_msg,(void *)"world\n");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
}
void * print_msg(void* s){
    char* m = (char*)s;
    int i = 0;
    for(i = 0; i < 5;i++){
        printf("%s",m);
        fflush(stdout);
        sleep(1);
    }
    return NULL;
}