//
// Created by Misaka on 2/11/2019.
//

#include "wincondition.h"
#include "gamemaker.h"
#include <stdio.h>
#include <stdbool.h>
#include "cursewindow.h"
#include "move.h"

bool gameover(Board* board, Data* data) {
    return win(board, data) || tie(board, data);
}
bool tie(Board* board, Data* data){
    int i,j;
    if(win(board, data)){
        return false;
    }
    for(i = 1; i<data->brow+1; i++){
        for (j=0; j<data->bcol; j++){
            if (board->theboard[i][j] == '*'){
                return false;
            }
        }
    }
    data->result = 0;
    return true;
}

bool win(Board* board, Data* data){
    return hwin(board, data) || vwin(board, data) || dwin(board, data);
}

bool dwin(Board* board, Data* data){
    return ldwin(board, data) || rdwin(board, data);
}

bool hwin(Board* board, Data* data){
    int i,j;
    int win = 0;
    char current;
    for (i = 1; i < data->brow+1; i++){
        for (j = 0; j < data->bcol; j++){
            if (board->theboard[i][j] == '*'){
                continue;
            }
            else if(board->theboard[i][j] != '*'){
                current = board->theboard[i][j];
                win = 0;
                for (int col = j; col < data->bcol; col++){
                    if (board->theboard[i][col] == current){
                        win++;
                        if (win == data->win){
                            if (current == 'X'){
                                data->winner = 1;
                                data->result = 1;
                            }else if(current == 'O'){
                                data->winner = 2;
                                data->result = 1;
                            }
                            return true;
                        }
                    }else{
                        break;
                    }
                }
            }
        }
    }
    return false;
}
bool vwin(Board* board, Data* data){
    int i,j;
    int win = 0;
    char current;
    for (i = 1; i < data->brow+1; i++){
        for (j = 0; j < data->bcol; j++){
            if (board->theboard[i][j] == '*'){
                continue;
            }
            else if(board->theboard[i][j] != '*'){
                current = board->theboard[i][j];
                win = 0;
                for (int row = i; row < data->brow+1; row++){
                    if (board->theboard[row][j] == current){
                        win++;
                        if (win == data->win){
                            if (current == 'X'){
                                data->winner = 1;
                                data->result = 1;
                            }else if(current == 'O'){
                                data->winner = 2;
                                data->result = 1;
                            }
                            return true;
                        }
                    }else if(board->theboard[row][j] != current){
                        break;
                    }
                }
            }
        }
    }
    return false;
}

bool ldwin(Board* board, Data* data) {
    int i, j;
    int dig = 0;
    int win = 0;
    char current;
    for (i = 1; i < data->brow + 1; i++) {
        for (j = 0; j < data->bcol; j++) {
            if (board->theboard[i][j] == '*') {
                continue;
            } else if (board->theboard[i][j] != '*') {
                current = board->theboard[i][j];
                while (true) {
                    if ((i + dig) > data->brow || (j + dig) > data->bcol ) {
                        if (win == data->win) {
                            if (current == 'X'){
                                data->winner = 1;
                                data->result = 1;
                            }else if(current == 'O'){
                                data->winner = 2;
                                data->result = 1;
                            }
                            return true;
                        } else {
                            return false;
                        }
                    } else {
                        if (board->theboard[i + dig][j + dig] == current) {
                            win++;
                            dig++;
                        } else {
                            win = 0;
                            dig = 0;
                            break;
                        }
                        if (win == data->win){
                            if (current == 'X'){
                                data->winner = 1;
                                data->result = 1;
                            }else if(current == 'O'){
                                data->winner = 2;
                                data->result = 1;
                            }
                            return true;
                        }else{
                            continue;
                        }

                    }
                }
            }
        }
    }
    return false;
}
bool rdwin(Board* board, Data* data){
    int i, j;
    int dig = 0;
    int win = 0;
    char current;
    for (i = 1; i < data->brow + 1; i++) {
        for (j = 0; j < data->bcol; j++) {
            if (board->theboard[i][j] == '*') {
                continue;
            } else if (board->theboard[i][j] != '*') {
                current = board->theboard[i][j];
                while (true) {
                    if ((i - dig) < 0 || (j + dig) > data->bcol) {
                        if (win == data->win) {
                            if (current == 'X'){
                                data->winner = 1;
                                data->result = 1;
                            }else if(current == 'O'){
                                data->winner = 2;
                                data->result = 1;
                            }
                            return true;
                        } else {
                            return false;
                        }
                    } else {
                        if (board->theboard[i - dig][j + dig] == current) {
                            win++;
                            dig++;
                        } else {
                            win = 0;
                            dig = 0;
                            break;
                        }
                        if (win == data->win){
                            if (current == 'X'){
                                data->winner = 1;
                                data->result = 1;
                            }else if(current == 'O'){
                                data->winner = 2;
                                data->result = 1;
                            }
                            return true;
                        }else{
                            continue;
                        }

                    }
                }
            }
        }
    }
    return false;
}