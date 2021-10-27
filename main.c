#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"



int main(void) {
  int max_size = 200;

  enemy enemies[max_size];
  int numEnemies;
  numEnemies = PopulateEnemies(enemies, max_size);

  // enemy enemies[max_size];
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
  srand((unsigned) time(&t)); //unique seed
  // int secondPath;
  // int thirdPath;
  // int fourthPath;
  int numOfPaths=4;
  int userPathChoise;
  int usrGold = 5;
  int level = 0;
  int usrSword, usrArmor = 0;
  int userPathChoice;
  int userElementChoice;
  //Get user name, set difficulty, set monster Damage per hit
  GetIntroductionInfo(name, &difficulty, &monsterDamagePerHit);
  while(lives>0 && level < 10){
	  if(fightWon == 1){
		srand(time(0));
		monster1 = GetRandomNum(numEnemies, 0);
		monster2 = GetRandomNum(numEnemies, 0);
		monster3 = GetRandomNum(numEnemies, 0);
	  }
	  if(level == 0){
	      printf("You are at the start of the catacombs.\n");
	  }
	  else{
	      printf("You are %d levels deep into the catacombs.\n", level);
	  }
	  //Print instructions for 1st Path
	  PrintPath(monster1, monster2, monster3, enemies, numEnemies);
	  GetUserPathChoice(&userPathChoise);
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
				GetUserPathChoice(&userPathChoise);
			}
	  }
	  if(fightWon == 1){
		level++;
	  }
  }


  //display instructions based on user Path Choise. 
  //for ex. if 1. Left is a dim, 2. Center - A loud roar, 3. Right there is only quietness
  //if user chose 1, the function will give info from Left is a dim.. etc.
  //FirstPath(userPathChoice);


  //PrintAttackElements();
  //GetUserAttackElementChoice(&userElementChoice);
  //DamageToMonsters(userElementChoice, enemies.element);

  //GetAndPrintUserAttackElementChoice(&userElementChoice);
  // DamageToMonsters(userElementChoise, enemies.element);


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

////-------------------------------------------------- 
    

  // 	for(int x = 0; x<i; x++){
	// 	printf("Tunnel Hint: %s\n", enemies[x].tunnelHint);
	// 	printf("Enemy Name: %s\n", enemies[x].name);
	// 	printf("Enemy Element: %s\n", enemies[x].element);
	// 	printf("Prompt: %s\n", enemies[x].startingPrompt);
	// 	printf("Ascii art: \n");
	// 	int j = 0;
	// 	while(strcmp(enemies[x].asciiArt[j],"next") != 0){
	// 		printf("%s\n", enemies[x].asciiArt[j]);
	// 		j++;
	// 	}
	// }




  return 0;
}
