#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"



int main(void) {
  int max_size = 200;
  enemy enemies[max_size];
  int numEnemies;
  numEnemies = PopulateEnemies(enemies, max_size);
  char name[30];
  int difficulty;
  int monsterDamagePerHit;
  // int* playerAttackDamage;
  int lives=3;
  int potions=0;
  int firstPath;
  int monster1;
  int monster2;
  int monster3;
  int fightWon = 1; //To comply with old c, 0 means false, 1 means true.
  time_t t;
  // int secondPath;
  // int thirdPath;
  // int fourthPath;
  int numOfPaths=4;
  int userPathChoise;
  //Get user name, set difficulty, set monster Damage per hit
  GetIntroductionInfo(name, &difficulty, &monsterDamagePerHit);
  while(lives>0){
	  if(fightWon == 1){
		srand(time(0));
		monster1 = rand() % numEnemies;
		monster2 = rand() % numEnemies;
		monster3 = rand() % numEnemies;  
	  }
	  //Print instructions for 1st Path
	  PrintPath(monster1, monster2, monster3, enemies, numEnemies);
	  GetUserPathChoise(&userPathChoise);
	  switch (userPathChoise){
		  case 1:
			PrintEnemyPrompts(monster1, enemies);
			break;
		  case 2:
			PrintEnemyPrompts(monster2, enemies);
			break;
		  case 3:
			PrintEnemyPrompts(monster3, enemies);
			break;
		  default:
			printf("This is not a valid path\n");
			while(userPathChoise != 1 && userPathChoise != 2 && userPathChoise != 3){
				GetUserPathChoise(&userPathChoise);
			}
	  }
  }



  
  //RANDOMLY SELECT ONE OF OUR 4 PATHS (4 DIFFERENT MONSTERS)
  firstPath=GetRandomNum(numOfPaths, 1);
 

  


  //create a function that passes in firstPath and userPathChoise and then gives
  //appropriate directions
  //create a function inside the above, in game.c that takes you to specific instructions based on path and userPathChoise


  




// //------------------------------------
//   //USE THis LATER to randomly select paths that were not used before:
//   secondPath=GetRandomPathNum(numOfPaths,1);
//   thirdPath=GetRandomPathNum(numOfPaths,1);
//   fourthPath=GetRandomPathNum(numOfPaths,1);


//   //Randomly select each path and ensure we don't have the same path twice
//   //create a function for this
//   while (secondPath==firstPath){
//     secondPath=GetRandomPathNum(numOfPaths,1);
//   }
//   while (thirdPath==firstPath || thirdPath==secondPath){
//     thirdPath=GetRandomPathNum(numOfPaths,1);
//   }
//   while (fourthPath==firstPath || fourthPath==secondPath || fourthPath==thirdPath){
//     fourthPath=GetRandomPathNum(numOfPaths,1);
//   }
  
//   printf("my 1st is %d, my 2nd is %d, my 3rd is %d,my 4th is %d", firstPath, secondPath, thirdPath, fourthPath);

////--------------------------------------------------- 

  return 0;
}