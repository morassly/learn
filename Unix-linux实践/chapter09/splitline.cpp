#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "smsh.h"
#define BUFSIZE 20
char* next_cmd(char* prompt, FILE* fp) {
    char c;
    int pos = 0, bufspace = 0;
    char* buf;
    printf("%s", prompt);
    while ((c = getc(fp)) != EOF) {
        if (pos + 1 >= bufspace) {
            if (bufspace == 0) {
                buf = (char*) malloc(BUFSIZE);
            } else {
                buf = (char*)realloc(buf,bufspace+BUFSIZ);
            }
            bufspace += BUFSIZE;
        }
        if (c == '\n')
            break;
        buf[pos++] = c;
    }
    if (c == EOF && pos == 0)
        return NULL;
    buf[pos] = '\0';
    return buf;
}
char** splitline(char* line){
    if (line == NULL)
        return NULL;
    char** args = (char**)malloc(BUFSIZE);
    int bufspace = BUFSIZE;
    int spots = BUFSIZE/sizeof(char*);
    int argnum = 0;
    char* cp = line;
    while (*cp != '\0'){
        while(*cp == ' ') cp++;
        if (*cp == '\0') break;
        if (argnum + 1 >= spots){
            bufspace += BUFSIZE;
            spots += (BUFSIZE/sizeof(char*));
            args = (char**)realloc(args,bufspace);
        }
        char* start = cp;
        int len = 1;
        while(*++cp != '\0' && *cp != ' ') len++;
        char* temp = (char*)malloc(len + 1);
        temp[len] = '\0';
        strncpy(temp,start,len);
        args[argnum++] = temp;
    }
    args[argnum] = NULL;
    return args;
}

void freelist(char** list){
    char** cp = list;
    while(*cp)
        free(*cp++);
    free(list);
}