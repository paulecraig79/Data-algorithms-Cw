#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "print.h"




#define Z 16

int check(int graph[Z][Z], int number, int y, int x)
{

    if (graph[y][x] != 0)
    {
        return 0;
    }
    
    if (number >16 || number < 1)
    {
        return 0;
    }
    

    for (int i = 0; i < 15; i++)
    {
        if (graph[y][i] == number)
        {
            return 0;
        }
        
    }

    for (int i = 0; i < 15; i++)
    {
        if (graph[i][x] == number)
        {
            return 0;
        }
        
    }

    int startx = x- x %4, starty = y - y %4;
    for (int j = 0; j < 4; j++)
    {
        for (int k = 0; k < 4; k++)
        {
            if (graph[j + starty][k + startx] == number)
            {
                return 0;
            }
            
        }
        
    }
    

    return 1;
    
    
    
}

int solver(int grid[Z][Z], int y, int x){

    if (y== Z-1 && x ==Z)
    {
        return 1;
    }

    if (x == Z)
    {
        y++;
        x = 0;
    }
    
    if (grid[y][x] > 0)
    {
        return solver(grid, y, x + 1);
    }

    for (int i = 0; i <= Z; i++)
    {
        if (check(grid, y, x, i) == 1 )
        {
            grid[y][x] = i;

            if (solver(grid, y, x+1) == 1)
            {
                return 1;
            }
            
        }

        grid[y][x] =0;
        
    }
    
    return 0;
    

}


void sudokuGen(int level ,int mode){
    int newBoard = 0;
    int targetCoverage;
    switch (level)
    {
    case 1:
        targetCoverage = 250;
        break;
    
    case 2:
        targetCoverage = 100;
        break;

    case 3:
        targetCoverage = 30;
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
            if (board[y][x] != num)
            {
                if (check(board, num, y, x) == 1 )
                {
                    board[y][x] = num;
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
    int score = 100;
    int flag;
    while (finish == 0)
    {
        xcoord = 0;
        ycoord = 0;
        num = 0;
  

        printf("Enter the X coordinate: ");
        scanf("%d", &xcoord);
        printf("\n");

        printf("Enter the Y coordinate: ");
        scanf("%d", &ycoord);

        printf("Enter the number: ");
        scanf("%d", &num);


        if(xcoord == 34 || ycoord == 34 || num == 34){
            printf("[redacted] developer commands:\n");
            printf("[1] solve sudoku ");
            scanf("%d", &flag);
            switch (flag)
            {
            case 1:
                if (solver(board, 0, 0) == 1)
                {
                    print(board);
                    finish = 1;
                    
                }
                else{
                    printf("no");
                }
                
                break;
            
            default:
                printf("error");
            }

            break;
        }



        if (check(board, num, ycoord, xcoord) == 1 )
        {
            board[ycoord][xcoord] = num;
        }

        else{
            printf("wrong\n");
            score = score - 1;
            if (mode == 1)
            {
                finish = 1;
                printf("Game Over!");
                break;
            }
            
        }
        print(board);

    }
    
    
}
