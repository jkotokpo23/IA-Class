#include <stdio.h>
#include <stdlib.h>
#ifndef GENERIC_STRUCT_H
#define GENERIC_STRUCT_H

typedef int ** gameBoard;

typedef struct {
    char letter;
    int row;
    int col;
} coordinate;

coordinate dictionary[] = {
    {'a', 0, 0},
    {'z', 0, 1},
    {'e', 0, 2},
    {'q', 1, 0},
    {'s', 1, 1},
    {'d', 1, 2},
    {'w', 2, 0},
    {'x', 2, 1},
    {'c', 2, 2}
};


gameBoard init_board();
int** cleanBoard(int ** mat);
void printBoard(gameBoard board);

#endif