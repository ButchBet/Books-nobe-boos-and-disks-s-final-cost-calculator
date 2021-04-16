#include <stdio.h>
#include <stdlib.h>

void main(void){
    unsigned char first[14] = {"ABCDEFGHIJKLM"};
    unsigned char second[14] ={"NOPQRSTUVWXYZ"};
    char problem[9] = {"COLOMBIA"};
    char change[9] = {"--------"};
    unsigned char reading[1];
    int lives = 5;
    int oport = 0; /* oportunities */
    int win = 0; /* check if the player has won */

    //Begin the game
    while(lives > 0 && win < 8){
        /* Show spaces and the letters to choose */
        printf("\n");
        puts(change);
        puts(first);
        puts(second);

        /* Require letter*/
        printf("Enter the letter: ");
        fflush(stdin); // Use this built-in function to can clear the buffer and can read reading againg
        scanf("%c", &reading[0]);
        
        /* Change the choosed char in the first and second array for a X*/
        //system("cls");
        for(int j = 0; j < 13; j++){
            if(reading[0] == first[j]){
                first[j] = 'X';
                break;
            }else if(reading[0] == second[j]){
                second[j] = 'X';
                break;
            }else{}
        }
        /* Checking for posible or nor-posible matches */
        oport = 0;
        for(int i = 0; i < 8; i++){
            if(reading[0] == problem[i]){
                change[i] = problem[i];
                oport = 1;
                win++;
                printf("\n-->%i\n-->%i\n", win, oport);
            }else{}
        }printf("\n**>%i\n", oport);

        /* verify if the entered character has mached or not */
        if(oport == 0){
            lives--;
            
        }
        printf("\n<3%i\n", lives);
    }  
    puts(change);
    puts(first);
    puts(second); 
}
