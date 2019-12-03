
#include "cursewindow.h"
#include "gamemaker.h"

Boardwin boardwindow(int numRows, int numCols, int rowStart, int colStart){
Boardwin gamewindow;
gamewindow.Window = newwin(numRows-1, numCols, 1, colStart);
gamewindow.Window2 = newwin(1, numCols, rowStart, colStart);
gamewindow.Window3 = newwin(1, 13, numRows - 1, colStart);
gamewindow.cursorrow = 0;
gamewindow.cursorcol = 0;
gamewindow.cursorrow2 = 0;
gamewindow.cursorcol2 = 0;
gamewindow.cursorrow3 = 0;
gamewindow.cursorcol3 = 0;
return gamewindow;
}

void make_board1(Boardwin* win, char star){
    int i,j;
    int row = win->cursorrow;
    int col = win->cursorcol;
    char* w1 = "Window";
    char* w2 = "Window2";
    char* w3 = "Window3";

    for (i = 0; i < (getrow(win, w1)-1); i++){
        for ( int j = 0; j < getcol(win, w1); j++){
            mvwaddch(win->Window, i, j, star);
        }
    }
    wmove(win->Window, win->cursorrow, win->cursorcol);
    wmove(win->Window2, win->cursorrow2, win->cursorcol2);
}

int getrow(Boardwin* win, char* whichwindow){
    if (whichwindow == "Window"){
        return getmaxy(win->Window);
    }
    else if (whichwindow == "Window2"){
        return getmaxy(win->Window2);
    }
    else if (whichwindow == "Window3"){
        return getmaxy(win->Window3);
    }
}
int getcol(Boardwin* win, char* whichwindow){
    if (whichwindow == "Window"){
        return getmaxx(win->Window);
    }
    else if (whichwindow == "Window2"){
        return getmaxx(win->Window2);
    }
    else if (whichwindow == "Window3"){
        return getmaxx(win->Window3);
    }
}

void result_window(Data* data, Boardwin* win){
    if (data->result == 0){
        for (int p = 0; p<7; p++){
            mvwaddstr(win->Window3, 0, 0, "Tie Game");
        }
    }
    else if(data->result == 1){
        if (data->winner == 1){
            mvwaddstr(win->Window3, 0, 0, "Player 1 Won!");
        }
        else if(data->winner == 2){
            mvwaddstr(win->Window3, 0, 0, "Player 2 Won!");
        }
    }
    wrefresh(win->Window3);
}
