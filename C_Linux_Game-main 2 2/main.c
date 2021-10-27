#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"



int main(void) {
  int max_size = 200;
  enemy enemies[max_size];
  int i;
  i=PopulateEnemies(enemies, max_size);
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
  int userPathChoice;
  int userElementChoice;



  //Get user name, set difficulty, set monster Damage per hit
  GetIntroductionInfo(name, &difficulty, &monsterDamagePerHit);
  
  //RANDOMLY SELECT ONE OF OUR 4 PATHS (4 DIFFERENT MONSTERS)
  firstPath=GetRandomNum(numOfPaths, 1);
  
  //Print instructions for 1st Path
  PrintPath(firstPath);

  GetUserPathChoice(&userPathChoice);

  //display instructions based on user Path Choise. 
  //for ex. if 1. Left is a dim, 2. Center - A loud roar, 3. Right there is only quietness
  //if user chose 1, the function will give info from Left is a dim.. etc.
  FirstPath(userPathChoice);

  PrintAttackElements();
  GetUserAttackElementChoice(&userElementChoice);
  DamageToMonsters(userElementChoice, enemies.element);

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
    
  	for(int x = 0; x<i; x++){
		printf("Tunnel Hint: %s\n", enemies[x].tunnelHint);
		printf("Enemy Name: %s\n", enemies[x].name);
		printf("Enemy Element: %s\n", enemies[x].element);
		printf("Prompt: %s\n", enemies[x].startingPrompt);
		printf("Ascii art: \n");
		int j = 0;
		while(strcmp(enemies[x].asciiArt[j],"next") != 0){
			printf("%s\n", enemies[x].asciiArt[j]);
			j++;
		}
	}



  return 0;
}
