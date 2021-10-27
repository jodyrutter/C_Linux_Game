#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
  int sword = 0; //If sword is 1, they have a sword. If not, then this is 0.
  int armor = 0; //If armor is 1, they have a armor. If not, then this is 0.
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
  int usrGold = 500;
  int level = 0;
  int usrSword, usrArmor = 0;
  int userPathChoice;
  int userElementChoise;
  int monsterHealth;
  int playerHealth;
  
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
			//Fight function here
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


    monsterHealth=100;
    playerHealth=100;
    while(1){
      printf("\nMonster health is: %d\nPlayer health is: %d\nPlayer available lives: %d\n\n\n", monsterHealth, playerHealth, lives);
      GetAndPrintUserAttackElementChoice(&userElementChoise);

      //we need to pass in the enemy Type to get correct damage
      PrintDamageMonsterTook(&userElementChoise);
      //*******************need to pass in CalcDamToMonster the damage type, emenyType, sword, and monsterHealth
      CalculateDamageToMonster(&monsterHealth, userElementChoise, sword);
      if (monsterHealth<=0){
        printf("Congrats you have destroyed the monster\n");
        printf("You have advanced a level\n");
        fightWon=1;
        break;
      }
      CalculateDamageToPlayer(&playerHealth, difficulty);
      if (playerHealth<=0){
          printf("You have lost all your health\n");
          lives --;
          if (lives>0){
            printf("Available lives: %d", lives);
            break;
          }
          else{
            printf("---------------------------\n");
            printf("---------------------------\n");
            printf("---------GAME OVER---------\n");
            printf("---------------------------\n");
            printf("---------------------------\n");
            return 0;
          }
      }
    }
    //Create function to print player health and lives and monster health
    //in the function, if user has portions, ask user if they want to use 1
    //

    //create function in game.c for the following:
    printf("\n\n\n\n");



	  if(fightWon == 1){
		level++;
	  }
	  ShopKeeper(&usrGold, &sword, &potions, &armor, &lives);


  }






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
