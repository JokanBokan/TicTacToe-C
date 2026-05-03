#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#include "macros.h"
#include "utils.h"
#include "board.h"

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int input1, input2, result;
    while(1) {
        clearConsole();
        printf("\nENTER THE SLOT INDEX(1-3) YOU WANNA PUT YOUR SYMBOL(%c) IN: ", user);
        scanf("%d %d", &input1, &input2);
        if(input1 > 3 || input1 < 1 || input2 > 3 || input2 < 1) {
            printf("\nERROR: SLOTS CANT BE BIGGER THAN 3 OR SMALLER THAN 1");
            wait(1.5);
            continue;
        }
        if(isSlotBusy(board, input1, input2)) {
            printf("\nERROR: THAT SLOT IS ALREADY BUSY");
            wait(1.5);
            continue;
        }

        board[input1 - 1][input2 - 1] = user;
        clearConsole();
        printTable(board);
        wait(3.5);
        result = shouldGameFinish(board);
        if(result != 0) break;
        clearConsole();
        puts("\nAI is thinking");
        wait(1.5);
        AIRandomPutSlot(board);
        clearConsole();
        printTable(board);
        wait(2.5);
        result = shouldGameFinish(board);
        if(result != 0) break;
    }
    clearConsole();
    if(result != 3) {
        printf("\nThe winner is: %s, Congrats!!!", (result == 1 ? "You" : "AI"));
        wait(3);
    }
    else {
        wait(3);
        printf("\nDraw!");
    }
    return 0; 

}
