#include <curses.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    initscr();
    clear();
    for (int i = 0; i < LINES; i++) {
        move(i, 2 * i);
        if (i % 2) standout();
        addstr("Hello World");
        if (i % 2) standend();
        refresh();
        sleep(1);
        move(i, 2 * i);
        addstr("           ");
    }
    endwin();
    return 0;
}