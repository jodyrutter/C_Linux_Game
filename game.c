#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "game.h"

//predefine functions
void PrintPath1();
void PrintPath2();
void PrintPath3();
void PrintPath4();
int SetDifficulty(int userDif);
void GetValidateUserInputDigit(int* myInput, int lowerRange, int higherRange);
int minDif=1; //min count for difficulty - starts at 1 - Beginner
int maxDif=3; //max count for difficulty - ends at 1 - Advanced
void PrintUserDigitOptions(int min, int max);

void GetIntroductionInfo(char userName[], int *userDifficulty, int *monsterDamage){
  printf("Hello adventurer, what is your name?\n");
  // scanf("%s", userName);
  strcpy(userName, "Elenie"); //for testing only
  printf("\nNice to meet you %s.\nYou have been called here to explore these vast catacombs in search of great treasure and riches.\n\n", userName);
  printf("What difficulty would you like?\n");
  printf("--------------------------\n");
  printf("1. Beginner\n2. Intermediate\n3. Advanced\n");
  printf("--------------------------\n");
  PrintUserDigitOptions(minDif, maxDif);
  GetValidateUserInputDigit(userDifficulty, minDif, maxDif);
  // userDifficulty=1; //for testing only
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
  int basedamage = 20;
//  Based off the defined user difficulty, pads damage output based off the difficulty and basedamage variable
//  damage is range based generated randomly from rand/srand
    if (userDif==1){
      printf("You chose Beginner");
      //damage = rand() % (basedamage + 1 - 0) + 0; might be needed for testing
      damage = GetRandomNum(basedamage, 0);
    }
    else if(userDif==2){
      printf("You chose Intermediate");
      //damage = rand() % (basedamage + 10 + 1 - 10) + basedamage - 10;
      damage = GetRandomNum((basedamage + 10), 10);
    }
    else if(userDif==3){
      printf("You chose Advanced");
      //damage = rand() % (basedamage + 20 + 1 - 20) + basedamage - 20;
      damage = GetRandomNum((basedamage + 20), 20);
    }
    else{
      printf("Not a valid choice. Please try again!!!");
      return 0;
      
    }
    printf("\n");
    return damage;
}
void GetUserPathChoise(int *pathChoise){
  int minPathChoise=1;
  int maxPathChoise=3;
  
  PrintUserDigitOptions(minPathChoise, maxPathChoise);
  
  GetValidateUserInputDigit(pathChoise, minPathChoise, maxPathChoise);
  printf("\n");
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
  else if (path==2){
    PrintPath2();
  }
  else if (path==3){
    PrintPath3();
  }
  else{
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
  printf("1. Left - You hear rocks falling down this tunnel.\n2. Center - There is the sound of rushing water coming from this tunnel.\n3. Right - There is a dim light somewhere down this tunnel.\n\n");
}
void PrintPath4(){
  printf("FIX ME -- CREATE PATH\n\n");
}

int DamageToMonsters(int damageType, enemy enemyType) {
	/*
	 * Simple damage function that looks like struct enemy element and then assigns damage accordingly
	 * currently set to be static can be converted to dynamic depending on difficulty etc...
	*/
	int monsterDamage;

	if (damageType == 1 || damageType == 2 || damageType == 3 || damageType == 4) {

      if (damageType == 1) {
        if (strcmp(enemyType.element, "Water")) {
          monsterDamage = 40;
        }
        else {
          monsterDamage = 20;
        }
      }
      else if (damageType == 2) {
          if (strcmp(enemyType.element, "Fire")) {

            monsterDamage = 40;
          }
          else {
            monsterDamage = 20;
          }
        }
      else if (damageType == 3) {
          if (strcmp(enemyType.element, "Air")) {

            monsterDamage = 40;
          }
          else {
            monsterDamage = 20;
          }
        }
      else{
          if (strcmp(enemyType.element, "Earth")) {

            monsterDamage = 40;
          }
          else {
            monsterDamage = 20;
          }
       }
  }
	return monsterDamage;
}

void GameOver(int lives, int playerHealth) { //Function to determine Game Over
    while (lives > 0) {
        if (playerHealth <= 0) {
            lives = lives - 1; //Decrement lives from game
            if (lives <= 0) {
                printf("Game Over");
            }
        }
     }
}




/**
 * Function to populate an array of enemies with data from file.
 * 
 * @param enemies An array of enemies to populate.
 * @param max_size Maximum size of the array to populate.
 * @return The number of enemies.
 */
int PopulateEnemies(enemy enemies[], int max_size){
	FILE *fptr; //Declare a file to open.
	char *line = NULL;  //Declare a line variable to read in a file line by line.
	size_t len = 0; //Declare a length variable to read in length of a line in a file.
	size_t read; //Variable to determine if end of file is reached.
	fptr = fopen("enemy.txt", "r"); //Open enemy.config for reading in contents.
	//Loop to read in contents of enemy.config line by line and create and populate the struct array with enemies.
	int i = 0;
	read = getline(&line, &len, fptr);
	while(read != -1 && i < max_size){
		strcpy(enemies[i].tunnelHint, line);
		read = getline(&line, &len, fptr); //Read in another line for enemy name.
		strcpy(enemies[i].name, line);
		read = getline(&line, &len, fptr); //Read in another line for element.
		strcpy(enemies[i].element, line);
		read = getline(&line, &len, fptr); //Read in another line for starting prompt.
		strcpy(enemies[i].startingPrompt, line);
		read = getline(&line, &len, fptr); //Read in another line for ascii art.
		int j = 0;
		line[strcspn(line, "\r\n")] = 0;
		while(strcmp(line, "next") != 0 && j < 49){
			strcpy(enemies[i].asciiArt[j], line);
			read = getline(&line, &len, fptr); //Read in another line for ascii art.
			line[strcspn(line, "\r\n")] = 0;
			j++;
		}
		strcpy(enemies[i].asciiArt[j], "next");
		read = getline(&line, &len, fptr);
		i++;
	}
	fclose(fptr);
    return i;
}



void FirstPath(int pathChoise){
  if (pathChoise == 1){
    printf("You have chosen Left");
  }
  else if(pathChoise == 2){
    printf("You have chosen Center");
  }
  else if(pathChoise ==3){
    printf("You have chosen Right");
  }
  printf("\n\n");
}

//function that prints Fire, Water,Earth, Air
void PrintAttackElements(int min, int max){
  printf("Choose which element to attack with:\n");
  printf("--------------------------\n");
  printf("1. Fire\n2. Water\n3. Earth\n4. Air\n");
  printf("--------------------------\n");
  PrintUserDigitOptions(min, max);
}

//Print attack elements fire, water, earth, air and get userInput choise
void GetAndPrintUserAttackElementChoise(int *elementChoise){
  int elementNum=4;
  int minNum = 1;

  PrintAttackElements(minNum, elementNum);

  GetValidateUserInputDigit(elementChoise, minNum, elementNum);
  printf("my new element %d\n", *elementChoise);
}

//Print: Type 1, 2 or 3    (changes depending on min or max)                   
void PrintUserDigitOptions(int min, int max){
  int i;
  printf("Type ");
  for (i=min; i<max; i++){
    printf("%d, ", i);
  }
  printf("or %d: ", max);
}

void GetValidateUserInputDigit(int* myInput, int lowerRange, int higherRange){
    scanf("%d", myInput);
      //check if user input is within range. 
      //Program breaks if user input anything other than a number (infinite loop)
    while ( *myInput >higherRange || *myInput <lowerRange){
          printf("******ERROR*****\n");
          printf("You have selected %d which is out of range, please select an option between %d and %d\n", *myInput, lowerRange, higherRange);
          printf("Enter here: ");
          scanf("%d", myInput);
          printf("\n");
    }

}