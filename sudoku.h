#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "print.h"




#define Z 16


void copyTable(int graph1[Z][Z], int graph2[Z][Z])
{
    int num;
    for (int i = 0; i < Z; i++)
    {
        for (int j = 0; j < Z; j++)
        {
            num = graph1[i][j];
            graph2[i][j] = num;
        }
        
    }
}


void clearTable(int graph[Z][Z])
{
    for (int i = 0; i < Z; i++)
    {
        for (int j = 0; j < Z; j++)
        {
            graph[i][j] = 0;
        }
        
    }
    
}

int findEmpty(int graph[Z][Z], int *y, int *x)
{
    for (int i = 0; i < Z; i++)
    {
        for (int j = 0; j < Z; j++)
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









int solver(int graph[Z][Z])
{
    int x, y;
  
    if (findEmpty(graph, &y, &x) == 0)
    {
        return 1;
    }

    for (int i = 0; i <= 16; i++)
    {
        if (check(graph, i, y, x))
        {
            graph[y][x] = i;

            if (solver(graph))
            {
                return 1;
            }

            graph[y][x] = 0;
            
        }
        
    }
    
    return 0;
}

int checkWin(int grid[Z][Z])
{
    
    for (int i = 0; i < Z; i++)
    {



        

        for (int j = 0; j < Z; j++)
        {

            if (grid[i][j] == 0)
            {
                return 0;
            }
            
                
                

                
            

        }
        
        
    }
    return 1;
}












void sudokuGen(int mode){
    int newBoard = 0;
    int targetCoverage = 10;
    int counter;
    
    
    int coverage = 0;
    int table[Z][Z] = {{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};

    int correctTable[Z][Z] = {{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};


    while (newBoard == 0)
    {
        counter = counter + 1;
        srand(counter);
        int x = rand() % 17;
        int y = rand() % 17;
        int num = rand() % 17;

        if (coverage == targetCoverage)
        {


            copyTable(table, correctTable);

            if (solver(correctTable) == 1)
            {
                
                newBoard = 1;
            }
            else
            {
                
                clearTable(table);
                clearTable(correctTable);
                coverage = 0;
            }
            
            
           
         
            
        }
        else
        {
            if (table[y][x] != num)
            {
                if (check(table, num, y, x) == 1 )
                {
                    table[y][x] = num;
                    coverage =coverage + 1;
                }
                
                
                
            }
            
           
            
        }
        
        


    }
    print(table);
    int finish =0;
    int xcoord;
    int ycoord;
    int num;
    int score = 100;
    int flag;
    int correctAnswer;
    while (finish == 0)
    {
        xcoord = 0;
        ycoord = 0;
        num = 0;
  

        printf("Enter the X coordinate: ");
        scanf("%d", &xcoord);

        printf("Enter the Y coordinate: ");
        scanf("%d", &ycoord);

        printf("Enter the number: ");
        scanf("%d", &num);

        correctAnswer = correctTable[ycoord][xcoord];

        if (xcoord == 34 && ycoord == 34 && num == 34)
        {
            solver(table);
            print(table);

        }

        if (checkWin(table) == 1)
        {
            printf("Win  Score: %d", score);
            break;
        }
        



        if (check(table, num, ycoord, xcoord) == 1 && correctAnswer == num)
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
        print(table);
        if (checkWin(table) == 1)
        {
            printf("Win  Score: %d", score);
            break;
        }

    }
    
    
}
