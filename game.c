#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

//predefine functions
void PrintPath1();
void PrintPath2();
void PrintPath3();
void PrintPath4();
int SetDifficulty(int userDif);



void GetIntroductionInfo(char userName[], int *userDifficulty, int *monsterDamage){
  printf("Hello adventurer, what is your name?\n");
  scanf("%s", userName);
  // strcpy(name, "Elenie"); //for testing only
  printf("\nNice to meet you %s.\nYou have been called here to explore these vast catacombs in search of great treasure and riches.\n\n", userName);
  printf("What difficulty would you like?\n");
  printf("--------------------------\n");
  printf("1. Beginner\n2. Intermediate\n3. Advanced\n");
  printf("--------------------------\n");
  printf("Type 1, 2, or 3: ");
  scanf("%d", userDifficulty);
  // difficulty=1; //for testing only
  printf("\n");
  //Print difficulty, Set damage taken by monster based on level
  *monsterDamage=SetDifficulty(* userDifficulty);
  printf("Monster Damage per hit is: %d\n", * monsterDamage);
  printf("\n");
}


//set level difficulty and damage taken by monsters
//Beginner 20, Intermediate 30, Advanced 40
int SetDifficulty(int userDif){
  int damage;
    if (userDif==1){
      printf("You chose Beginner");
      damage = 20;
    }
    else if(userDif==2){
      printf("You chose Intermediate");
      damage = 30;
    }
    else if(userDif==3){
      printf("You chose Advanced");
      damage = 40;
    }
    else{
      printf("Not a valid choice. Please try again!!!");
      return 0;
      
    }
    printf("\n");
    return damage;
}



//GET RANDOM PATH
void srand(unsigned int seed);

int GetRandomNum(int numUpTo, int startAtNum){
  int myRandomNum;
  time_t t;
  srand((unsigned) time(&t)); //unique seed
  myRandomNum = (rand() % numUpTo)+startAtNum; //ex. (rand() % 4)+1  - get numbers 1 to 4
  //  Get random numbers 1-4
  return myRandomNum;
}




void PrintPath(int path)
{
  printf("To start, pick a path\n");
  
  if (path==1){
    PrintPath1();
  }
  if (path==2){
    PrintPath2();
  }
  if (path==3){
    PrintPath3();
  }
  if (path==4){
    PrintPath4();
  }
}


void PrintPath1(){
  printf("1. Left - There is a dim light somewhere down this tunnel.\n2. Center - A loud roar has erupted from this tunnel.\n3. Right - There is only quietness from this tunnel. \n\n"); 
}

void PrintPath2(){
  printf("1. Left - This tunnel sounds very windy.\n2. Center - There is a dim light somewhere down this tunnel.\n3. Right - A woman's voice can be heard coming from this tunnel. Her voice is beautiful\n\n");
}
void PrintPath3(){
  printf("1. Left - You hear rocks falling down this tunnel.\n2. Center - There is the sound of rushing water coming from this tunnel.\n3. Right - There is a dim light somewhere down this tunner.\n\n");
}
void PrintPath4(){
  printf("FIX ME -- CREATE PATH");
}


