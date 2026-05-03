#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "macros.h"

void printTable(char board[3][3]) {
    printf("    1    2    3  \n");
    for(int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for(int j = 0; j < 3; j++) {
            printf("| %c |", board[i][j]);
        }
        puts("\n");
    }
}

bool isSlotBusy(char board[3][3], int row, int column) {
    if(row > 3 || row < 1 || column > 3 || column < 1)
        return true;

    if(board[row - 1][column - 1] == user || board[row-1][column-1] == AI)
        return true;

    return false;
}

int shouldGameFinish(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if(board[i][0] == user) {
                return 1; 
            }
            else if(board[i][0] == AI) {
                return 2;
            }
        }
    }
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if(board[0][i] == user)
                return 1;
            else if(board[0][i] == AI)
                return 2;
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0] == user ? 1 : 2;
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2] == user ? 1 : 2;
    }

    int space = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != user && board[i][j] != AI) {
                space++;
            }
        }
    }

    if(space == 0)
        return 3;
    return 0;
} 

void AIRandomPutSlot(char board[3][3]) {       
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(!isSlotBusy(board, i + 1, j + 1)) {
                board[i][j] = AI;
                return;
            }
        }
    }
}   
