#include "cursewindow.h"
#include "gamemaker.h"
#include "move.h"
#include <stdio.h>
#include <stdbool.h>
#include "wincondition.h"

Move checkvalidinput(Boardwin* win, Turn turn, Data* data, Board* board, FILE* fp){
    Move move;
    int i, j, k;
    move.marker = "XO"[turn];
    waddch(win->Window2, move.marker);
    wmove(win->Window2, win->cursorrow2, win->cursorcol2);
    while(true){
        char key = wgetch(win->Window2);
        //can put log fcuction here, everytime a key is pressed.
        if (key == 'a' || key == 'j'){
            if (win->cursorcol2 == 0){
                waddch(win->Window2, ' ');
                win->cursorcol2 = (data->bcol - 1);
                mvwaddch(win->Window2, win->cursorrow2, win->cursorcol2, move.marker);
                wmove(win->Window2, win->cursorrow2, win->cursorcol2);
                for (k=0; k<board->col; k++){
                    if (board->theboard[0][k] != ' '){
                        board->theboard[0][k] = ' ';
                    }
                }
                board->theboard[0][win->cursorcol2] = move.marker;
            }
            else if(win->cursorcol2 > 0){
                waddch(win->Window2, ' ');
                win->cursorcol2 -= 1;
                mvwaddch(win->Window2, win->cursorrow2, win->cursorcol2, move.marker);
                wmove(win->Window2, win->cursorrow2, win->cursorcol2);
                for (k=0; k<board->col; k++){
                    if (board->theboard[0][k] != ' '){
                        board->theboard[0][k] = ' ';
                    }
                }
                board->theboard[0][win->cursorcol2] = move.marker;
            }
        }
        else if (key == 's' || key == 'k'){
            if (win->cursorcol2 == data->bcol -1){
                waddch(win->Window2, ' ');
                win->cursorcol2 = 0;
                mvwaddch(win->Window2, win->cursorrow2, win->cursorcol2, move.marker);
                wmove(win->Window2, win->cursorrow2, win->cursorcol2);
                for (k=0; k<board->col; k++){
                    if (board->theboard[0][k] != ' '){
                        board->theboard[0][k] = ' ';
                    }
                }
                board->theboard[0][win->cursorcol2] = move.marker;
            }
            else if(win->cursorcol2 > 0 || win->cursorcol2 == 0){
                waddch(win->Window2, ' ');
                win->cursorcol2 += 1;
                mvwaddch(win->Window2, win->cursorrow2, win->cursorcol2, move.marker);
                wmove(win->Window2, win->cursorrow2, win->cursorcol2);
                for (k=0; k<board->col; k++){
                    if (board->theboard[0][k] != ' '){
                        board->theboard[0][k] = ' ';
                    }
                }
                board->theboard[0][win->cursorcol2] = move.marker;
            }
        }
        else if (key == ' ' || key == '\n'){
            if (board->theboard[1][win->cursorcol2] != '*'){
                for (i = 0; i < board->row; i++){ //something is wrong with the log function, the main reason could be the timing and condition, think carefully about that.
                    for(j = 0; j < board->col; j++){
                        fprintf(fp, "%c", board->theboard[i][j]);
                    }
                    fprintf(fp, "%c", '\n');
                }
                fprintf(fp, "%c", '\n');
                fprintf(fp, "%c", '\n');
                continue;//wmove(win->Window2, win->cursorrow2, win->cursorcol2);
            }
            win->cursorcol = win->cursorcol2;
            move.ccol = win->cursorcol2;
            return move;
        }
        for (i = 0; i < board->row; i++){ //something is wrong with the log function, the main reason could be the timing and condition, think carefully about that.
            for(j = 0; j < board->col; j++){
                fprintf(fp, "%c", board->theboard[i][j]);
            }
            fprintf(fp, "%c", '\n');

        }
        fprintf(fp, "%c", '\n');
        fprintf(fp, "%c", '\n');
    wrefresh(win->Window2);
    }
}

void place_marker(Move* move, Boardwin* wind, Board* board, FILE* fp, Data* data){
    int i,j;
    char m1 = 'X';
    char m2 = 'O';
    for (i=0; i<board->col; i++){
        if (board->theboard[0][i] != ' '){
            board->theboard[0][i] = ' ';
        }
    }
    if (move->marker == m1){
        board->theboard[0][move->ccol] = m2;
    }
    else if(move->marker == m2){
        board->theboard[0][move->ccol] = m1;
    }
    //board->theboard[0][move->ccol] = move->marker;
    for (i = (getmaxy(wind->Window) - 1);i >= 0; i--){
        if (board->theboard[i][move->ccol] == '*'){
            board->theboard[i][move->ccol] = move->marker;
            mvwaddch(wind->Window, i-1, move->ccol, move->marker);
            wmove(wind->Window2, wind->cursorrow2, wind->cursorcol2);
            if (gameover(board, data)){
                if (win(board, data)){
                    if (move->marker == m1){
                        board->theboard[0][move->ccol] = m1;
                        for (i = 0; i < board->row; i++){ //something is wrong with the log function, the main reason could be the timing and condition, think carefully about that.
                            for(j = 0; j < board->col; j++){
                                fprintf(fp, "%c", board->theboard[i][j]);
                            }
                            fprintf(fp, "%c", '\n');
                        }
                        fprintf(fp, "%s", "Player 1 won!");
                        fprintf(fp, "%c", '\n');
                    }
                    else if(move->marker == m2){
                        board->theboard[0][move->ccol] = m2;
                        for (i = 0; i < board->row; i++){ //something is wrong with the log function, the main reason could be the timing and condition, think carefully about that.
                            for(j = 0; j < board->col; j++){
                                fprintf(fp, "%c", board->theboard[i][j]);
                            }
                            fprintf(fp, "%c", '\n');
                        }
                        fprintf(fp, "%s", "Player 2 won!");
                        fprintf(fp, "%c", '\n');
                    }
                }
                else if(tie(board, data)){
                    if (move->marker == m1){
                        board->theboard[0][move->ccol] = m1;
                    }
                    else if(move->marker == m2){
                        board->theboard[0][move->ccol] = m2;
                    }
                    for (i = 0; i < board->row; i++){ //something is wrong with the log function, the main reason could be the timing and condition, think carefully about that.
                        for(j = 0; j < board->col; j++){
                            fprintf(fp, "%c", board->theboard[i][j]);
                        }
                        fprintf(fp, "%c", '\n');
                    }
                    fprintf(fp, "%s", "Tie Game");
                    fprintf(fp, "%c", '\n');
                }
            }else {
                for (i = 0; i < board->row; i++){ //something is wrong with the log function, the main reason could be the timing and condition, think carefully about that.
                    for(j = 0; j < board->col; j++){
                        fprintf(fp, "%c", board->theboard[i][j]);
                    }
                    fprintf(fp, "%c", '\n');
                }
                fprintf(fp, "%c", '\n');
                fprintf(fp, "%c", '\n');
            }
            break;
        }
    }

    wrefresh(wind->Window);
}
