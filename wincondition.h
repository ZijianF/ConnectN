//
// Created by Misaka on 2/11/2019.
//

#ifndef CONNECTN_WINCONDITION_H
#define CONNECTN_WINCONDITION_H
#include <stdbool.h>
#include <stdio.h>
#include "gamemaker.h"
bool gameover(Board* board, Data* data);
bool tie(Board* board, Data* data);
bool win(Board* board, Data* data);
bool hwin(Board* board, Data* data);
bool vwin(Board* board, Data* data);
bool dwin(Board* board, Data* data);
bool ldwin(Board* board, Data* data);
bool rdwin(Board* board, Data* data);
#endif //CONNECTN_WINCONDITION_H
