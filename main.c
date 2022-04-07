#include <stdio.h>


int main(int argc, char **argv)
{
    int input;
    printf("Sudoku game\n");
    printf("[1]Start [2]Leaderboard [3]Settings [4]Exit\n");

    scanf("%d",&input);
    printf("Input = %d", input);
    return 0;
}