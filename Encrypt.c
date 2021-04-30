#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

/*
#include <stdbool.h>
#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif*/

int main(){   
    // Add unsigned to can use all of the Ascci characters, the signed only is until 128
    unsigned char public_key[11] = {"HelloWord!"};
    unsigned char private_key[11];
    unsigned char change_key[11];

    /* bool encrypt = false; */
    /*Check if the encryption has been done
    if(encrypt == true){ Use it when learn about function 
        puts(private_key);
    }else{}*/


    srand(time(NULL)); /* search to understand better this*/
    /* fill the private array with random values */
    for(int i = 0; i < 10; i++){
        private_key[i] = ((rand()%(255-33))+32);
    }
    //Print the private and public _key
    puts(private_key);
    puts(public_key);

    /* Change the values to the public_key for the addtion */
    for(int i = 0; i < 10; ++i)
    {
        int add = (int)(public_key[i] + private_key[i]);
        if(add > 254){ /* know if the value is greater than max value in the Ascci table*/
            change_key[i] = private_key[i]; /* Save the public_key value to use when
            the user wants to decrypt it */       
            public_key[i] = private_key[i];
        }else{
            change_key[i] = (char)50;
            public_key[i] = (char)add;
        }
    }

    // show the encryped key
    printf("-->");
    puts(public_key);
    puts(change_key);
        
    // Make user to choose id what to finish or decrypt
    printf("1. Decrypt the keyFinish\nOther. Finish\n-->");
    int op;
    scanf("%i", &op);
    if(op == 1){
        system("cls");
        puts("Hello World!");
    }else{
        system("cls");
        exit(1);
    }   
}