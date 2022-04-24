#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "print.h"
#include "sudoku.h"
#include "UI.h"

#define Z 16

int main(int argc, char **argv)
{
    srand(time(0));

    int input;
    printf("16 x 16 Sudoku game\n");
    printf("[1]Start [2]Leaderboard [3]Settings [4]Exit\n");

    scanf("%d",&input);

    switch(input)
    {
        case 1:
            play();
            break;
        
        case 2:
            printf("Leaderboard");
            break;
        
        case 3:
            printf("Settings");
            break;
        
        case 4:
            printf("Exit");
            
            break;

       

        default:
            printf("Error! Incorrect input!\n");
    }
    
    
    return 0;
}

