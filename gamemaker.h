//
// Created by truma on 2/5/2019.
//

#ifndef CONNECTN_GAMEMAKER_H
#define CONNECTN_GAMEMAKER_H
#include <stdio.h>
typedef struct data_element{
    int brow;
    int bcol;
    int win;
    char* path;
    int winner;
    int result;
}Data;

typedef struct board_element{
    int row;
    int col;
    char** theboard;
}Board;

Data getdata(int argc, char* argv[]);
Board mboard(Data* data);
void freeboard(Board* board);

#endif //CONNECTN_GAMEMAKER_H
