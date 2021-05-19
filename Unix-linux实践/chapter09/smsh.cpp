#include "smsh.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void setup();
int main() {
    char *cmdline, *prompt, **arglist;
    int result;
    prompt = "> ";
    setup();
    while ((cmdline = next_cmd(prompt, stdin)) != NULL) {
        if ((arglist = splitline(cmdline)) != NULL) {
            if (strcmp(arglist[0], "exit") == 0) {
                freelist(arglist);
                free(cmdline);
                break;
            }
            result = execute(arglist);
            freelist(arglist);
        }
        free(cmdline);
    }
}

void setup() {
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
}
