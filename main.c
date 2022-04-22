#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define Z 16

void print(int game[Z][Z] ){

    char line[20];
    for (int i = 0; i < Z; i++)
    {


        
        
        
        

        if (i == 4 || i ==8 || i == 12)
        {
            printf(" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - \n");
            printf("|");
        }
        else{
            printf("|");
        }
        

        

        for (int j = 0; j < Z; j++)
        {
            if (game[i][j] >= 10)
            {
                printf("%d ",game[i][j]);
                
                
                if (j ==3 || j ==7 || j == 11 || j == 15)
                {
                    printf("|");
                }
                
                
                
            }
            else
            {
                printf("%d  ",game[i][j]);
                if (j == 3 || j == 7 || j == 11 || j == 15)
                {
                    printf("|");
                 
                }
                
            }
            
            

        }
        printf("\n");
        
    }
    
}

int check(int graph[Z][Z], int number, int x, int y)
{

    for (int i = 0; i < 15; i++)
    {
        if (graph[x][i] == number)
        {
            return 0;
        }
        
    }

    for (int i = 0; i < 15; i++)
    {
        if (graph[i][y] == number)
        {
            return 0;
        }
        
    }

    int startx = x- x %4, starty = y - y %4;
    for (int j = 0; j < 4; j++)
    {
        for (int k = 0; k < 4; k++)
        {
            if (graph[j + startx][k + starty] == number)
            {
                return 0;
            }
            
        }
        
    }
    

    return 1;
    
    
    
}

void sudokuGen(int level){
    int newBoard = 0;
    int targetCoverage;
    switch (level)
    {
    case 1:
        targetCoverage = 0;
        break;
    
    case 2:
        targetCoverage = 100;
        break;

    case 3:
        targetCoverage = 130;
        break;

    default:
        printf("Error! Try Again!");
    }
    
    int coverage = 0;
    int board[Z][Z] = {{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
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
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};



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
                if (check(board, num, x, y) == 1 )
                {
                    board[x][y] = num;
                    coverage =coverage + 1;
                }
                
                
                
            }
            
           
            
        }
        
        


    }
    print(board);
    int finish =0;
    int xcoord;
    int ycoord;
    int num;
    while (finish == 0)
    {
        xcoord = 0;
        ycoord = 0;
        num = 0;
        printf("X coords? ");
        scanf("%d\n", &xcoord);

        printf("y coords? ");
        scanf("%d\n", &ycoord);

        printf("what number would you like to input? ");
        scanf("%d\n", &num);

        board[xcoord][ycoord] = num;

        print(board);

    }
    
    
}




void normal(){
    int level;
    printf("[1]Easy [2]Medium [3]Hard\n");
    scanf("%d",&level);
    
    sudokuGen(level);
    

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