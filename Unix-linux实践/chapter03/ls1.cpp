#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
void do_ls(const char* dirname);
int main(int argc, char** argv){
    if (argc == 1){
        do_ls(".");
    } else {
        while (--argc)
        {
            do_ls(*++argv);
        }
    }
    return 0;
}
void do_ls(const char* dirname){
    DIR *dir_ptr;
    struct dirent *direntp;
    
    if((dir_ptr = opendir(dirname)) != NULL){
        while((direntp = readdir(dir_ptr))!=NULL){
            printf("%s\n",direntp->d_name);
        }
        closedir(dir_ptr);
    } else {
        fprintf(stderr,"cannot open %s\n",dirname);
    }
}