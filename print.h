#pragma once

#include <stdio.h>
#include <stdlib.h>
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