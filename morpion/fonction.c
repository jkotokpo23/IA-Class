#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int * allocOneDim(int n){
    int * tab;
    tab = (int *)malloc(n * sizeof(int));
    if(tab == NULL) printf("Erreur allocation");
    return tab;
}

int ** allocMat(int n, int m){
    int ** mat;
    mat = (int **)malloc(m * sizeof(int));
    if(mat == NULL) printf("Erreur allocation");
    for(int i = 0; i < n; i++){
        mat[i] = allocOneDim(n);
    }
    return mat;
}

int* libTabUneDim(int* tab){
    free(tab);
    tab = NULL;
    return tab;
}

int** cleanBoard(int ** mat){
    int m = 3;
    for(int i = 0; i < m; i++){
        mat[i] = libTabUneDim(mat[i]);
    }
    free(mat);
    return mat;
}

gameBoard init_board()
{
    gameBoard board;
    board = allocMat(3, 3);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = 0;
        }
    }
    return board;
}

void printBoard(gameBoard board){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %d |", board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    
    gameBoard board = init_board();
    printBoard(board);
    board = cleanBoard(board);
    
    return 0;
}