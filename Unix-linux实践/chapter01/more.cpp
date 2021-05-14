#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

constexpr int PAGE_LEN = 24;
constexpr int LINE_LEN = 512;

void more(FILE* fp) {
    char line_buffer[LINE_LEN];
    FILE* ttyp;
    int line_read, getchar_num;
    char c;

    if ((ttyp = fopen("/dev/tty", "r")) == nullptr) {
        printf("tty open failed");
        exit(0);
    }

    while (fgets(line_buffer, LINE_LEN, fp)) {
        if (line_read == PAGE_LEN) {
            printf("\n\033[7m more? \033[m");
            while ((c = getc(ttyp)) != EOF) {  //这儿的数据是/dev/tty传入的
                if (c == 'q') {
                    fclose(fp);
                    exit(0);
                } else if (c == '\n') {
                    getchar_num = 1;
                    break;
                } else if (c == ' ') {
                    getchar_num = 24;
                    break;
                }
            }

            line_read -= getchar_num;
        }
        if (fputs(line_buffer, stdout) == EOF) {
            exit(0);
        }

        line_read++;
    }
}
int main(int argc, char** argv) {
    FILE* fp;
    if (argc == 1) {
        more(stdin);
    } else {
        while (argc--) {
            if ((fp = fopen(*++argv, "r")) != nullptr) {
                more(fp);
                fclose(fp);
            } else {
                break;
            }
        }
    }
    return 0;
}
