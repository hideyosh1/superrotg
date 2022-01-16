#include <ncursesw.h>
#include <iostream>

int main(){
    
    initscr(); //initialize
    noecho(); //pass directly
    cbreak(); //allow ctrlc

    keypad(stdscr, true); //allow arrow keys
    curs_set(0);//invis cursor 

    int sx, sy;
    getmaxyx(stdscr, sy, sx);

    WINDOW* mainwin = newwin(sy - 7, sx, 0, 0); //height width ycorner xcorner
    //plan to load from a 2d std::vector, this time with an std::vector of chars
    WINDOW* promptwin = newwin(7, sx, sy - 7, 0);
    //making a new pad every time is a pain
}