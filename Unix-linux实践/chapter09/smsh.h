#include <stdio.h>
char* next_cmd(char* prompt, FILE* fp);
char** splitline(char* line);
void freelist(char**);
int execute(char**);