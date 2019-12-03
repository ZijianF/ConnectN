
#include "gamemaker.h"
#include <stdio.h>
#include <stdlib.h>

Data getdata(int argc, char* argv[]){
    Data data;
    data.brow = atoi(argv[1]);
    data.bcol = atoi(argv[2]);
    data.win = atoi(argv[3]);
    data.path = argv[4];
    return data;
}

Board mboard(Data* data){
    Board board;
    int i;
    int j;
    board.row = data->brow + 1;
    board.col = data->bcol;
    board.theboard = NULL;
    board.theboard = (char**) realloc(board.theboard, (board.row) * sizeof(char*)); // is it ok to just print the statement as a string under the matrix?
    for(i = 0; i < board.row; i++){
        (board.theboard)[i] = (char*)malloc(board.col * sizeof(char));
    }
    for (i = 0; i<board.col; i++){
        board.theboard[0][i] = ' ';
       // printf("%c", board.theboard[0][i]);
    }
    for (i = 0; i<board.row-1; i++){
        for (j = 0; j<board.col; j++){
            board.theboard[i+1][j] = '*';
        }
    }
    return board;
}

void freeboard(Board* board){
    for (int i = 0; i < board->row; i++){
        free(board->theboard[i]);
    }
    free(board->theboard);
    board->theboard = NULL;
    board->row = 0;
    board->col = 0;
}