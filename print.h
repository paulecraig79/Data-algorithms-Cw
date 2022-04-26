#pragma once

#include <stdio.h>
#include <stdlib.h>
#define Z 16
#define Y 4
#define L 9

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
    printf(" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - \n");
    
}

void printEz(int game[Y][Y])
{
    char line[20];
    printf("  0 1  2 3 -- x\n");
    for (int i = 0; i < Y; i++)
    {


        
        
        
        
        if (i == 2 )
        {
            printf("  - -  - -   \n");
            printf("%d", i);
            printf("|");
        }
        else{
            printf("%d", i);
            printf("|");
        }
        
        

        for (int j = 0; j < Y; j++)
        {
                printf("%d ",game[i][j]);
                
                if (j ==1)
                {
                    printf("|");
                }
            

        }
        printf("|");
        printf("\n");
        
    }
    printf("  - -  - - \n");
    
}

void printMid(int game[L][L])
{
    char line[20];
    printf("  0 1 2  3 4 5  6 7 8 -- x\n");
    for (int i = 0; i < L; i++)
    {
         

        
        
        
        

        if (i == 3 || i ==6 )
        {
            printf("  -  -  -  -  -  -  -  \n");
            printf("%d", i);
            printf("|");
        }
        else{
            printf("%d", i);
            printf("|");
        }
        

        
       
        for (int j = 0; j < L; j++)
        {
               
                printf("%d ",game[i][j]);
                
                
                if (j ==2 || j ==5 || j == 8)
                {
                    printf("|");
                }
                
            

        }
        printf("\n");
        
    }
    
    
}