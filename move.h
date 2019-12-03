
#ifndef CONNECTN_MOVE_H
#define CONNECTN_MOVE_H
#include <ncurses.h>
typedef enum{p1 = 0, p2 =1}Turn;

typedef struct move_struct{
    int crow, ccol;
    char marker;
}Move;

Move checkvalidinput(Boardwin* win, Turn turn, Data* data, Board* board, FILE* fp);

void place_marker(Move* move, Boardwin* win, Board* board,FILE* fp, Data* data);

#endif //CONNECTN_MOVE_H
