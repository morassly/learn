#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define Buffsize 512
ino_t get_inode(const char* filename) {
    struct stat info;
    if (stat(filename, &info) == -1) {
        fprintf(stderr, "cannot stat ");
        perror(filename);
        exit(1);
    }
    return info.st_ino;
}
void find_name(ino_t inode, char* name) {
    DIR* dir_ptr;
    if ((dir_ptr = opendir(".")) == NULL) {
        perror(".");
        exit(1);
    } else {
        struct dirent* direntp;
        while ((direntp = readdir(dir_ptr)) != NULL) {
            if (direntp->d_ino == inode) {
                strcpy(name, direntp->d_name);
                closedir(dir_ptr);
                return;
            }
        }
        exit(1);
    }
}
void pwd(ino_t cur_node) {
    if (get_inode("..") != cur_node) {
        chdir("..");
        char name[Buffsize];
        find_name(cur_node, name);
        pwd(get_inode("."));
        printf("/%s", name);
    }
}
int main() {
    pwd(get_inode("."));
    putchar('\n');
    return 0;
}