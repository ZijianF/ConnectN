

#ifndef CONNECTN_CURSEWINDOW_H
#define CONNECTN_CURSEWINDOW_H

#include <ncurses.h>
#include "gamemaker.h"

typedef struct board_window{
    WINDOW* Window;
    WINDOW* Window2;
    WINDOW* Window3;
    int cursorrow, cursorcol, cursorrow2, cursorcol2, cursorrow3, cursorcol3;
}Boardwin;

Boardwin boardwindow(int numRows, int numCols, int rowStart, int colStart);

void make_board1(Boardwin* win, char star);
int getrow(Boardwin* win, char* whichwindow);
int getcol(Boardwin* win, char* whichwindow);
void result_window(Data* data, Boardwin* win);

#endif //CONNECTN_CURSEWINDOW_H
