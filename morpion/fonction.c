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

int canPlay(gameBoard board, int i, int j){
    return board[i][j] == 0;
}

gameBoard play(gameBoard board, int turn, int i, int j){
    
    board[i][j] = turn;
    return board;
}

void changeTurn(int *turn){
    if(*turn == 1) *turn = -1;
    else *turn = 1;
}

int checkLine(gameBoard board, int turn, int i){
    int count = 0;
    while(count < 3 && board[i][count] == turn) count++;
    return(count == 3);
}

int checkColomn(gameBoard board, int turn, int j){
    int count = 0;
    while(count < 3 && board[count][j] == turn) count++;
    return(count == 3);
}

int checkFirstDiag(gameBoard board, int turn, int i, int j){
    int count = 0;
    if (i == j) 
        while(count < 3 && board[count][count] == turn) count++;
    return(count == 3);
}

int checkSecDiag(gameBoard board, int turn, int i, int j){
    int count = 0;
    if(i + j == 2)
        while(count < 3 && board[count][2 - count] == turn) count++;
    return count == 3;
    
}

int checkingWin(gameBoard board, int turn, int i, int j) {
    return(checkLine(board, turn, i) || 
        checkColomn(board, turn, j) || 
        checkFirstDiag(board, turn, i, j) || 
        checkSecDiag(board, turn, i, j));
}

int checkinDraw(gameBoard board){
    int count = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != 0) count++;
        }
    }
    return count == 9;
}

int isGoingGame(gameBoard board){
    return (!checkinDraw(board));
}


void playing(gameBoard board){
    int turn = 1;
    int i, j;
    int winning = 0;
    while (isGoingGame(board) && !winning){
        printf("Joueur %d, entrez i\n", turn); scanf("%d", &i);
        printf("Joueur %d, entrez j\n", turn); scanf("%d", &j);
        if(canPlay(board, i, j)){
            board = play(board, turn, i, j);
            printBoard(board);
            winning = checkingWin(board, turn, i, j);
            if(winning) printf("Game won\n");
            
            changeTurn(&turn);
        }
    }
    
}

int main(){
    
    gameBoard board = init_board();
    printBoard(board);
    playing(board);
    board = cleanBoard(board);
    
    return 0;
}