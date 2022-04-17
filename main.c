#include <stdio.h>
#include <stdlib.h>

void normalsudoku(string level){
    printf("%s",&level);
}




void normal(){
    int level;
    printf("[1]Easy [2]Medium [3]Hard");
    scanf("%d",&level);
    normalsudoku(level);
    

}

void tChallenge(){
    printf("[1]Easy [2]Medium [3]Hard");
    
}

void oneLife(){
    printf("[1]Easy [2]Medium [3]Hard");
    
}


void play(){
    int playinput;
    printf("[1]Normal [2]Time Challenge [3]One Life");
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
            printf("Error! Incorrect input!");
    }
    
}






int main(int argc, char **argv)
{
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
            printf("Error! Incorrect input!");
    }
    
    
    return 0;
}