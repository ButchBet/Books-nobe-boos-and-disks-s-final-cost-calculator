#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

/* The simply call clrscr(). On windows, it will use conio.h's clrscr(), 
and on linux, It will use Ansi scape codes. 
#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
//#define clrscr() printf("\033[H\033[J");
#define clrscr() printf("\e[1;1H\e[2J");
#endif*/

//X and O constant varible
#define X (char)88
#define O (char)79

// Prototype functions
void name_registration(void);
void draw_board(void);
int verify();
void reading_position(int inx);
void setting_position(int inx, char ch);


// variables to use
//-----------------
char position_mark[3][3] = {{(char)65, (char)66, (char)67},{(char)68, (char)69, (char)70}, {(char)71, (char)72, (char)73}};
// Position to mark X or O in each case.
char *p_mark = &position_mark[0][0]; // position_mark;
// char *p_mark = &position_mark[0][0];

char names[2][30]; 
// players name to don't use pi and p2 as reference

char choose[1]={(char)65};
/* choosing varible to can save, compare and replace it with
the position_mark array */
char *p_ch = &choose[0];

bool id  = true; /* Used to can require position to each player and don't
 repit a reading*/
bool change = false; /* Used to can stop a nested loop when the readed 
character has been changed */

int count = 0; // to can know if any entered choose is inside the range

/*NOTE: we are having a little problem in the reading position function,
  always returns a double call of the reading statement */

int c_ch = 0; /* to count the times that a valid value is entered, in total 
it's 9 enteres values*/
int saved_verify = 3; // to continue with the reding
int cp1=0, cp2=0; /*  Verify is there's any 3 match */

int main(void){
  system("cls");
  printf("Wellcome to tiki's game.");
  name_registration();
  return 0;
}

// Name registration function
void name_registration(void){
  printf("\nEnter the players name --> "); scanf("%s %s", &names[0][0], &names[1][0]);
  printf("\n\n");

  draw_board();
}

// Drawing board function
void draw_board(void){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf("     %c    ", position_mark[i][j]); /*Here we are using 
characters as references to can change it for X or O in the respective
case. */
    }printf("\n\n");
  }

  /* conditional to can verify if player 1 or 2 had won, make draw or any
case */
  verify();
  switch(saved_verify){
  case 0:
    printf("%s is the winer, congratulation.", names[0]);
    printf("\n");
    break;
  case 1:
    printf("%s is the winer, congratulation.", names[1]);
    printf("\n");
    break;
  case 2:
    printf("This is a draw.");
    printf("\n");
    break;
  default:
    if(id){
      reading_position(0); // require position to p1
    }else{
      reading_position(1); // require position to p2
    }
  }
}

// verify game status
int verify(){ // We have to evalueate 8 differetn cases
  for(int i = 0; i < 3; i++){ //horizontal cordenates
    cp1 = 0;
    cp2 = 0;/* cp1 and co2 work know that in each line we have mached
the 3 values */
    for(int j = 0; j < 3; j++){
      if(position_mark[i][j] == X){
  cp1++;
      }
      else if(position_mark[i][j] == O){
  cp2++;
      }else{continue;}
    }
    if(cp1 == 3 || cp2 == 3){
      i = 3; // to force stoping the loop
    }else{continue;}
  }
  
  if(cp1 == 3){
    saved_verify = 0;
  }
  else if(cp2 == 3){
    saved_verify = 1;
  }else{
    for(int k = 0; k < 3; k++){ // vertical cases
      cp1 = 0;
      cp2 = 0;
      for(int g = 0; g < 3; g++){  
        if(position_mark[g][k] == X){   
          cp1++;
  }
        else if(position_mark[g][k] == O){
    cp2++;
        }else{continue;}
      }
      if(cp1 == 3 || cp2 == 3){
      k = 3;
      }else{continue;}
    }
    if(cp1 == 3){
      saved_verify = 0;
    }
    else if(cp2 == 3){
      saved_verify = 1;
    }else{ // diagonal cases Note: Here you can use another loop to compare the position when the row and column index  are the same
      if(position_mark[0][0] == X && position_mark[1][1] == X && position_mark[2][2] == X || position_mark[0][2] == X && position_mark[1][1] == X && position_mark[2][0] == X){
  saved_verify = 0;
      }
      else if(position_mark[0][0] == O && position_mark[1][1] == O && position_mark[2][2] == O || position_mark[0][2] == O && position_mark[1][1] == O && position_mark[2][0] == O){
  saved_verify = 1;
      }
      else if(c_ch == 9){
        saved_verify = 2;
      }else{saved_verify = 3;}
    }
  }
}    


// Get player 1 and 2 options to change it for X or O respectively
void reading_position(int inx){
  printf("%s please choose --> ", names[inx]);
  scanf("%c", &choose[0]);

  // Here we are verifying that choose is insithe the range
  for(int i = 65; i < 74; i++){
    if(choose[0] == (char)i){
      setting_position(inx, choose[0]);
      count = 1;
      break;
    }else{
      count = 0;
      continue;}
  }
  /* compare choose with each position_mark character to change it to X
or O in each case */
  if(count == 0){
    reading_position(inx);
  }else{} // allways use this else thus don't have any code line inside
}


void setting_position(int inx, char ch){
  change = false; /* We need to re-initialize change to false to let the 
increment of the loop varieble i */
  for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
  if(ch  == position_mark[i][j]){
    switch(inx){ // to change for X or O y in the case
    case 0:
      position_mark[i][j] = X;
      id = false;
      change = true;
      c_ch++;
      break;
    case 1:
      position_mark[i][j] = O;
      id = true;
      change = true;
      c_ch++;
      break;
    }
  }else{
    continue;
  }
  if(change){
    break; // Here you can change this for i = 3;
  }else{continue;}
      }
      if(change){
        system("cls"); // clean screen
        draw_board(); // draw the board with the new data
  break;
      }
    }
}
