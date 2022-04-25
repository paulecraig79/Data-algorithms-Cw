#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "print.h"




#define Y 4

int checkEz(int graph[Y][Y], int number, int y, int x)
{

    if (graph[y][x] != 0)
    {
        return 0;
    }
    
    if (number >4 || number < 1)
    {
        return 0;
    }
    

    for (int i = 0; i < 3; i++)
    {
        if (graph[y][i] == number)
        {
            return 0;
        }
        
    }

    for (int i = 0; i < 3; i++)
    {
        if (graph[i][x] == number)
        {
            return 0;
        }
        
    }

    int startx = x- x %2, starty = y - y %2;
    for (int j = 0; j < 2; j++)
    {
        for (int k = 0; k < 2; k++)
        {
            if (graph[j + starty][k + startx] == number)
            {
                return 0;
            }
            
        }
        
    }
    

    return 1;
    
    
    
}









int solverEz(int grid[Y][Y], int y, int x){

    if (y== Y-1 && x ==Y)
    {
        return 1;
    }

    if (x == Y)
    {
        y++;
        x = 0;
    }
    
    if (grid[y][x] > 0)
    {
        return solverEz(grid, y, x + 1);
    }

    for (int i = 0; i <= Z; i++)
    {
        if (checkEz(grid, y, x, i) == 1 )
        {
            grid[y][x] = i;

            if (solverEz(grid, y, x+1) == 1)
            {
                return 1;
            }
            
        }

        grid[y][x] =0;
        
    }
    
    return 0;
    

}




int checkWinEz(int grid[Y][Y])
{
    
    for (int i = 0; i < Y; i++)
    {


        
        
        
        



        

        

        for (int j = 0; j < Y; j++)
        {

            if (grid[i][j] == 0)
            {
                return 0;
            }
            
                
                

                
            

        }
        
        
    }
    return 1;
}









void sudokuGenEz(int mode){
    int newBoard = 0;
    int targetCoverage = 5;

    
    int coverage = 0;
    int table[Y][Y] = {{ 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 }};



    while (newBoard == 0)
    {
        
        int x = rand() % 5;
        int y = rand() % 5;
        int num = rand() % 5;

        if (coverage == targetCoverage)
        {


            
            
           
            newBoard = 1;
            
        }
        else
        {
            if (table[y][x] != num)
            {
                if (checkEz(table, num, y, x) == 1 )
                {
                    table[y][x] = num;
                    coverage =coverage + 1;
                }
                
                
                
            }
            
           
            
        }
        
        


    }
    printEz(table);
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


        



        if (checkEz(table, num, ycoord, xcoord) == 1 )
        {
         
            table[ycoord][xcoord] = num;
        }

        else{
            printf("wrong\n");
            score = score - 15;
            if (mode == 1)
            {
                finish = 1;
                printf("Game Over!");
                break;
            }
            
        }
        printEz(table);

        if (checkWinEz(table) == 1)
        {
            printf("Win  Score: %d", score);
            
            break;
        }
        

    }
    
    
}
