#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "print.h"




#define Z 16

struct moves
{
    int y;
    int x;
    int num;
};

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
    

    for (int i = 0; i <= 15; i++)
    {
        if (graph[y][i] == number)
        {
            return 0;
        }
        
    }

    for (int i = 0; i <= 15; i++)
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
    int var = 20;
    int targetCoverage = 15;
    
    
    
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
        int counter = rand();
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
    int completeTBL = 0;
    copyTable(correctTable, table);
    
    for (int i = 0; i <= var; i++)
    {
        int completeTBL = 0;

        while (completeTBL == 0)
        {
            int row = rand() % 15;
            int col = rand() % 15;
            if (table[row][col] != 0)
            {

                table[row][col] = 0;
                completeTBL = 1;
            }
            
        }
        


    }
    
    








    print(table);
    int finish =0;
    int xcoord;
    int ycoord;
    int any;
    int num;
    int score = 100;
    int flag;
    int inp;
    int correctAnswer;
    int moveNumber = 0;
    
    struct moves move[var];
    
    while (finish == 0)
    {
        system("clear");
        print(table);
        xcoord = 0;
        ycoord = 0;
        num = 0;
        flag = 0;
        inp = 0;
  
        printf("[1]Enter number into table [2]Undo [3]Redo \n");
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
                printf("Nothing to undo to. \n");
            }
            
            else{
                moveNumber = moveNumber - 1;
                xcoord = move[moveNumber].x;
                ycoord = move[moveNumber].y;

                table[ycoord][xcoord] = 0;
            }
            break;

        case 3:
            printf("x[0]: %d\n",move[0].x);
            printf("x[1]: %d\n",move[1].x);
            printf("x[2]: %d\n",move[2].x);

            moveNumber = moveNumber + 1;
            xcoord = move[moveNumber].x;
            ycoord = move[moveNumber].y;
            num = move[moveNumber].num;


            
            
            break;
            

        default:
            printf("Error\n");
        }

        if(inp == 1)
        {
            if (check(table, num, ycoord, xcoord) == 1 && correctAnswer == num)
            {
                table[ycoord][xcoord] = num;
                move[moveNumber].x = xcoord;
                move[moveNumber].y = ycoord;
                move[moveNumber].num = num;

                if (checkWin(table) == 1)
                {
                    printf("Win  Score: %d \n", score);
                    printf("History of play: \n");

                    for (int i = 0; i <= moveNumber; i++)
                    {

                       
                        printf("%d   (%d,%d) %d \n", i, move[i].x, move[i].y, move[i].num);


                    }
                    printf("[1]Menu [2]Exit\n");

                    scanf("%d", &any);
                    if (any == 1)
                    {
                        system("clear");
                        Menu();
                    }

                    else
                    {
                        break;
                    }
                



                
                }

                moveNumber = moveNumber + 1;



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
        }

    }
    
    
}
