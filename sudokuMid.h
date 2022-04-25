#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "print.h"




#define L 9

int checkMid(int graph[L][L], int number, int y, int x)
{

    if (graph[y][x] != 0)
    {
        return 0;
    }
    
    if (number >9 || number < 1)
    {
        return 0;
    }
    

    for (int i = 0; i < 8; i++)
    {
        if (graph[y][i] == number)
        {
            return 0;
        }
        
    }

    for (int i = 0; i < 8; i++)
    {
        if (graph[i][x] == number)
        {
            return 0;
        }
        
    }

    int startx = x- x %3, starty = y - y %3;
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (graph[j + starty][k + startx] == number)
            {
                return 0;
            }
            
        }
        
    }
    

    return 1;
    
    
    
}









int solverMid(int grid[L][L], int y, int x){

    if (y== L-1 && x ==L)
    {
        return 1;
    }

    if (x == L)
    {
        y++;
        x = 0;
    }
    
    if (grid[y][x] > 0)
    {
        return solverMid(grid, y, x + 1);
    }

    for (int i = 0; i <= L; i++)
    {
        if (checkMid(grid, y, x, i) == 1 )
        {
            grid[y][x] = i;

            if (solverMid(grid, y, x+1) == 1)
            {
                return 1;
            }
            
        }

        grid[y][x] =0;
        
    }
    
    return 0;
    

}




int checkWinMid(int grid[L][L])
{
    
    for (int i = 0; i < L; i++)
    {


        
        
        
        



        

        

        for (int j = 0; j < L; j++)
        {

            if (grid[i][j] == 0)
            {
                return 0;
            }
            
                
                

                
            

        }
        
        
    }
    return 1;
}









void sudokuGenMid(int mode){
    int newBoard = 0;
    int targetCoverage = 40;

    
    int coverage = 0;
    int table[L][L] = {{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0 }};



    while (newBoard == 0)
    {
        
        int x = rand() % 10;
        int y = rand() % 10;
        int num = rand() % 10;

        if (coverage == targetCoverage)
        {


            
            
           
            newBoard = 1;
            
        }
        else
        {
            if (table[y][x] != num)
            {
                if (checkMid(table, num, y, x) == 1 )
                {
                    table[y][x] = num;
                    coverage =coverage + 1;
                }
                
                
                
            }
            
           
            
        }
        
        


    }
    printMid(table);
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


        



        if (checkMid(table, num, ycoord, xcoord) == 1 )
        {
         
            table[ycoord][xcoord] = num;
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
        printMid(table);

        if (checkWinMid(table) == 1)
        {
            printf("Win  Score: %d", score);
            break;
        }
        

    }
    
    
}
