#include <stdio.h>
#include <stdlib.h>
#include "H:\c coursework\play.h"


int main(int argc, char **argv)
{
    int input;
    printf("Sudoku game\n");
    printf("[1]Start [2]Leaderboard [3]Settings [4]Exit\n");

    scanf("%d",&input);
    printf("Input = %d", input);

    play();
    return 0;
}