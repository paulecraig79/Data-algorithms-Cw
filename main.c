#include <stdio.h>
#include <stdlib.h>

#define Z 16

void print(int game[Z][Z] ){
    
    for (int i = 0; i < Z; i++)
    {
        for (int j = 0; j < Z; j++)
        {
            if (game[i][j] >= 10)
            {
                printf("%d ",game[i][j]);
            }
            else
            {
                printf("%d  ",game[i][j]);
            }
            

        }
        printf("\n");
        
    }
    
}

void check(int graph[Z][Z], int number){

}

void sudokuGen(){
    int newBoard = 0;
    int targetCoverage = 130;
    int coverage = 0;
    int board[Z][Z] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };



    while (newBoard == 0)
    {
        int x = rand() % 16;
        int y = rand() % 16;
        int num = rand() % 16;

        if (coverage == targetCoverage)
        {
            newBoard = 1;
        }
        else
        {
            if (board[x][y] != num)
            {
                board[x][y] = num;
                coverage =coverage + 1;
                
            }
            
           
            
        }
        
        


    }
    print(board);
    
}




void normal(){
    int level;
    printf("[1]Easy [2]Medium [3]Hard\n");
    scanf("%d",&level);
    sudokuGen();
    

}

void tChallenge(){
    printf("[1]Easy [2]Medium [3]Hard\n");
    
}

void oneLife(){
    printf("[1]Easy [2]Medium [3]Hard\n");
    
}


void play(){
    int playinput;
    printf("[1]Normal [2]Time Challenge [3]One Life\n");
    scanf("%d",&playinput);
    
    switch(playinput){
        case 1:
            normal();
            break;
        
        case 2:
            tChallenge();
            break;
        
        case 3:
            oneLife();
            break;

        default:
            printf("Error! Incorrect input!\n");
    }
    
}






int main(int argc, char **argv)
{
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