#define _XOPEN_SOURCE_EXTENDED
//idfk why i have to define this
#include <ncursesw/curses.h>
#include <iostream>
#include <locale.h>

int main(){
    
    setlocale(LC_ALL, "");
    initscr(); //initialize
    noecho(); //pass directly
    cbreak(); //allow ctrlc

    keypad(stdscr, TRUE); //allow arrow keys
    curs_set(0);//invis cursor 

    int sx, sy;
    getmaxyx(stdscr, sy, sx);

    WINDOW* mainwin = newwin(sy - 7, sx, 0, 0); //height width ycorner xcorner
    //plan to load from a 2d std::vector, this time with an std::vector of chars
    WINDOW* promptwin = newwin(7, sx, sy - 7, 0);
    //making a new pad every time is a pain
    box(mainwin, 0, 0);
    box(promptwin, 0, 0);

    mvaddstr(0, 0, "for the best experience, please maximize your window.");

    if(has_colors() == FALSE){
        mvaddstr(3, 0, "unfortunately, your terminal doesn't support color.");
        mvaddstr(4, 0, "game will use black and white for the time being.");
        mvaddstr(5, 0, "for the best experience, it's recommended to switch to a terminal with color.");
        
    }
    if(can_change_color() == FALSE){
        mvaddstr(8, 0, "your terminal doesn't support changing colors.");
        mvaddstr(9, 0,)
    }

    endwin();
}