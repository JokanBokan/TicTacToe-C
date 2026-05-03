#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

void printTable(char board[3][3]);
bool isSlotBusy(char board[3][3], int row, int column);
int shouldGameFinish(char board[3][3]);
void AIRandomPutSlot(char board[3][3]);

#endif