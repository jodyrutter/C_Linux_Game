#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"



int main(void) {
  char name[30];
  int difficulty;
  int monsterDamagePerHit;
  // int* playerAttackDamage;
  // int lives=3;
  // int potions=0;
  int firstPath;
  // int secondPath;
  // int thirdPath;
  // int fourthPath;
  int numOfPaths=4;
   

  //STARTING GAME
  printf("Hello adventurer, what is your name?\n");
  scanf("%s", name);
  // strcpy(name, "Elenie"); //for testing only
  printf("\nNice to meet you %s.\nYou have been called here to explore these vast catacombs in search of great treasure and riches.\n\n", name);
  printf("What difficulty would you like?\n");
  printf("Type 1, 2, or 3\n");
  printf("--------------------------\n");
  printf("1. Beginner\n2. Intermediate\n3. Advanced\n");
  printf("--------------------------\n");
  scanf("%d", &difficulty);
  // difficulty=1; //for testing only
  printf("\n");
  //Print difficulty, Set damage taken by monster based on level
  monsterDamagePerHit=SetDifficulty(difficulty);
  printf("Monster Damage per hit is: %d\n", monsterDamagePerHit);
  printf("\n");

  //RANDOMLY SELECT ONE OF OUR 4 PATHS (4 DIFFERENT MONSTERS)
  firstPath=GetRandomPathNum(numOfPaths);
  
  //Print instructions for 1st Path
  PrintPath(firstPath);








// //------------------------------------
//   //USE THis LATER to randomly select paths that were not used before:
//   secondPath=GetRandomPathNum(numOfPaths);
//   thirdPath=GetRandomPathNum(numOfPaths);
//   fourthPath=GetRandomPathNum(numOfPaths);


//   //Randomly select each path and ensure we don't have the same path twice
//   //create a function for this
//   while (secondPath==firstPath){
//     secondPath=GetRandomPathNum(numOfPaths);
//   }
//   while (thirdPath==firstPath || thirdPath==secondPath){
//     thirdPath=GetRandomPathNum(numOfPaths);
//   }
//   while (fourthPath==firstPath || fourthPath==secondPath || fourthPath==thirdPath){
//     fourthPath=GetRandomPathNum(numOfPaths);
//   }
  
//   printf("my 1st is %d, my 2nd is %d, my 3rd is %d,my 4th is %d", firstPath, secondPath, thirdPath, fourthPath);

////--------------------------------------------------- 

  return 0;
}