#include <stdio.h>
#include <stdlib.h>
#ifndef GENERIC_STRUCT_H
#define GENERIC_STRUCT_H

typedef int ** gameBoard;


gameBoard init_board();
int** cleanBoard(int ** mat);
void printBoard(gameBoard board);

#endif