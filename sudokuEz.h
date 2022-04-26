#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "print.h"




#define Y 4

struct moves
{
    int y;
    int x;
    int num;
};


void copyTableEz(int graph1[Y][Y], int graph2[Y][Y])
{
    int num;
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            num = graph1[i][j];
            graph2[i][j] = num;
        }
        
    }
}


void clearTableEz(int graph[Y][Y])
{
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            graph[i][j] = 0;
        }
        
    }
    
}

int findEmptyEz(int graph[Y][Y], int *y, int *x)
{
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            if (graph[i][j] == 0)
            {

                *y = i;
                *x = j;


                return 1;
            }
            
        }
        
    }

    return 0;
    
}


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









int solverEz(int graph[Y][Y])
{
    int x, y;
  
    if (findEmptyEz(graph, &y, &x) == 0)
    {
        return 1;
    }

    for (int i = 0; i <= 4; i++)
    {
        if (checkEz(graph, i, y, x))
        {
            graph[y][x] = i;

            if (solverEz(graph))
            {
                return 1;
            }

            graph[y][x] = 0;
            
        }
        
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

    int counter;
    int coverage = 0;
    int table[Y][Y] = {{ 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 }};

    int correctTable[Y][Y] = {{ 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 },
                       { 0, 0, 0, 0 }};



    while (newBoard == 0)
    {
        counter = counter + 1;
        srand(counter);
        int x = rand() % 5;
        int y = rand() % 5;
        int num = rand() % 5;

        if (coverage == targetCoverage)
        {


            copyTableEz(table, correctTable);
            
           if (solverEz(correctTable) == 1)
           {
               printEz(correctTable);
               newBoard = 1;
           }
           else{
               clearTableEz(table);
               clearTableEz(correctTable);
               coverage = 0;
           }
           
            
            
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
    int inp;
    int correctAnswer;
    int moveNumber;
    struct moves move[10];
    while (finish == 0)
    {
        xcoord = 0;
        ycoord = 0;
        num = 0;
        flag = 0;
        inp = 0;
        

        printf("[1]Enter number into table [2]Undo");
        scanf("%d", &flag);

        switch (flag)
        {
        case 1:
            printf("Enter the X coordinate: ");
            scanf("%d", &xcoord);

            printf("Enter the Y coordinate: ");
            scanf("%d", &ycoord);

            printf("Enter the number: ");
            scanf("%d", &num);

            correctAnswer = correctTable[ycoord][xcoord];
            inp = 1;
            break;
        
        case 2:
            if (moveNumber == 0)
            {
                printf("Nothing to undo to.");
            }
            
            printf("undo");
            break;


        default:
            printf("Error");
        }





       



        
        if(inp == 1)
        {


            if (checkEz(table, num, ycoord, xcoord) == 1 && correctAnswer == num )
            {
            
                table[ycoord][xcoord] = num;
                move[moveNumber].x = xcoord;
                move[moveNumber].y = ycoord;
                move[moveNumber].num = num;

                if (checkWinEz(table) == 1)
                {
                    printf("Win  Score: %d \n", score);
                    printf("History of play: \n");

                    for (int i = 0; i <= moveNumber; i++)
                    {
                        printf("%d   (%d,%d) %d \n", i, move[i].x, move[i].y, move[i].num);
                    }
                


                break;
            }

                moveNumber = moveNumber + 1;
    

            
            }

            else
            {
                printf("wrong\n");
                score = score - 15;
                if (mode == 1)
                {
                    finish = 1;
                    printf("Game Over!");
                    break;
                }
                
            }
        }
        printEz(table);



    }
    
    
}
