#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define Z 16

void play();



void Menu()
{
    int input;
    printf("Sudoku game by 40482827\n");
    printf("[1]Start [2]Leaderboard [3]History Of Play [4]Exit\n");

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

            
            break;

        case 4:
            printf("Exit");
            
            break;

       

        default:
            printf("Error! Incorrect input!\n");
    }
}


void normal(){
    int level;
    printf("[1]Easy [2]Medium [3]Hard\n");
    scanf("%d",&level);
    switch (level)
    {
    case 1:
        sudokuGenEz(0);
        break;
    
    case 2:
        sudokuGenMid(0);
        break;

    case 3:
        sudokuGen(0);
        break;
    default:
        printf("Error");
    }
    
    

}

void tChallenge(){
    int level;
    printf("[1]Easy [2]Medium [3]Hard\n");
    scanf("%d",&level);
    
    sudokuGen(0);
}

void oneLife(){
    int level;
    printf("[1]Easy [2]Medium [3]Hard\n");
    scanf("%d",&level);
    
    sudokuGen(1);
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

