#include <ctype.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct arg_set {
    char* fname;
    int count;
};

struct arg_set* mailbox;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t flag = PTHREAD_COND_INITIALIZER;

int main(int argc, char** argv) {
    pthread_t t1, t2;
    struct arg_set args1, args2;
    void* count_words(void*);
    int reports_in = 0, tot_words = 0;
    if (argc != 3) {
        exit(1);
    }

    pthread_mutex_lock(&lock);
    args1.fname = argv[1];
    args1.count = 0;
    pthread_create(&t1, NULL, count_words, &args1);

    args2.fname = argv[2];
    args2.count = 0;
    pthread_create(&t2, NULL, count_words, &args2);

    while (reports_in < 2) {
        pthread_cond_wait(&flag, &lock);
        tot_words += mailbox->count;

        if (mailbox == &args1)
            pthread_join(t1, NULL);
        if (mailbox == &args2)
            pthread_join(t2, NULL);
        mailbox = NULL;
        pthread_cond_signal(&flag);
        reports_in++;
    }
    printf("%d:total word\n", tot_words);
}

void* count_words(void* a) {
    struct arg_set* args = (struct arg_set*)a;
    FILE* fp;
    int c, pre = '\0';
    if ((fp = fopen(args->fname, "r")) != NULL) {
        while ((c = getc(fp)) != EOF) {
            if (!isalnum(c) && isalnum(pre))
                args->count++;
            pre = c;
        }
        fclose(fp);
    }
    pthread_mutex_lock(&lock);
    if(mailbox != NULL)
        pthread_cond_wait(&flag,&lock);
    mailbox = args;
    pthread_cond_signal(&flag);
    pthread_mutex_unlock(&lock);
    return NULL;
}