#include <stdio.h>
#include <ncurses.h>
#include "gamemaker.h"
#include "cursewindow.h"
#include "move.h"
#include <stdbool.h>
#include "wincondition.h"
FILE* openfile(Data* data){
    FILE* fp = NULL;

    fp = fopen(data->path, "w");

    return fp;
}
int main(int argc, char* argv[]){
    initscr();
    noecho();
    cbreak();
    Data data = getdata(argc, argv);

    Boardwin gamewindow = boardwindow((data.brow)+2, data.bcol, 0, 0);
    make_board1(&gamewindow, '*');
    keypad(gamewindow.Window2, true);
    wrefresh(gamewindow.Window);
    wrefresh(gamewindow.Window2);
    wrefresh(gamewindow.Window3);
    FILE* fp = openfile(&data);
    Board board = mboard(&data);
    Turn turn = p1;
    mvwaddch(gamewindow.Window2, 0, 0, 'X');
    wmove(gamewindow.Window2, 0, 0);
    board.theboard[0][0]= 'X';
    for (int i = 0; i < board.row; i++){ //something is wrong with the log function, the main reason could be the timing and condition, think carefully about that.
        for(int j = 0; j < board.col; j++){
            fprintf(fp, "%c", board.theboard[i][j]);
        }
        fprintf(fp, "%c", '\n');
    }
    fprintf(fp, "%c", '\n');
    fprintf(fp, "%c", '\n');
    while(!gameover(&board, &data)){ //finish writing win condition tomorrow.
    //for(i = 0; i<6; i++){
        Move move = checkvalidinput(&gamewindow, turn, &data, &board, fp);

        place_marker(&move, &gamewindow, &board, fp, &data);

        if (turn == p1){
            turn = p2;
        }
        else if (turn == p2){
            turn = p1;
        }
    }
    result_window(&data, &gamewindow);
   // Move move= checkvalidinput(&gamewindow, turn, &data);

   // place_marker(&move, &gamewindow, &board);
  //  while (!gameover){
 //       Move move= checkvalidinput(&gamewindow, turn, &data);

 //   }




    //wrefresh(gamewindow.Window); //remember to  make this refresh action embeded into every time a move it made
    //wrefresh(gamewindow.Window2); // make this refresh everytime a valid key is pressed
    //wrsefresh(gamewindow.Window3); // only refresh this when the result it out.
    wgetch(gamewindow.Window2);
    delwin(gamewindow.Window);
    delwin(gamewindow.Window2);
    delwin(gamewindow.Window3);
    endwin();

    freeboard(&board);


    return 0;
}