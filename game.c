#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "game.h"

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
  time_t t;
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

void GetUserPathChoice(int *pathChoice){
  int minPathChoice=1;
  int maxPathChoice=3;
  
  PrintUserDigitOptions(minPathChoice, maxPathChoice);
  
  GetValidateUserInputDigit(pathChoice, minPathChoice, maxPathChoice);
  printf("\n");

}


//GET RANDOM PATH
void srand(unsigned int seed);

int GetRandomNum(int numUpTo, int startAtNum){
  int myRandomNum;
  myRandomNum = (rand() % numUpTo)+startAtNum; //ex. (rand() % 4)+1  - get numbers 1 to 4
  //  Get random numbers 1-4
  return myRandomNum;
}


void PrintEnemyPrompts(int enemyNum, enemy enemies[]){
	printf("%s\n\n\n", enemies[enemyNum].startingPrompt);
		int j = 0;
		while(strcmp(enemies[enemyNum].asciiArt[j],"next") != 0){
		printf("%s\n", enemies[enemyNum].asciiArt[j]);
		j++;
	}
}

void PrintPath(int monster1, int monster2, int monster3, enemy enemies[], int numEnemies)
{
  printf("Pick a path ('1', '2', or '3').\n");
  printf("---------------------------------\n");
  printf(" 1. Left - %s\n", enemies[monster1].tunnelHint);
  printf(" 2. Straight - %s\n", enemies[monster2].tunnelHint);
  printf(" 3. Right - %s\n", enemies[monster3].tunnelHint);
  printf("---------------------------------\n");
}

int RandomGold(int gold) {
	/*
	 * Simple gold generator, invoke on monster death or mon health <= 0
	 * gives gold min 10 max 25 and adds to gold purse.
	*/
	gold += GetRandomNum(25, 10);

	return gold;
}

int ShopKeeper(int *gold, int *sword, int *potions, int *armor, int *lives) {
	/*
	 * Takes input fold from the user and sword boolean int, if purchase is made
	 * gold is automatically subtracted
	 * Sword is permenant item once bought and gives slight attack dmg increase
	 * the armoring is a health buff item that can be purchased multiples times to make HP over 100
	 * health restore is a full health restoring potion if health is below base max of 100
	*/
	printf("Welcome to the shop traveller, see my wares below or enter q to exit!\n");
	char prompt = "";

	while(prompt != 'q' && *gold >= 10) {
	    //printf("\e[1;1H\e[2J");
	    printf("You have %d gold\n", *gold);
	    printf("You have %d potions\n", *potions);
	    printf("You have %d lives\n", *lives);
	    if(*sword==0){
	        printf("A. Sword(+10 dmg)\n");
		    printf("Gold cost: 10\n");
	    }
	    else{
	        printf("A. Lootbox\n");
	        printf("Gold cost: 10\n");
	    }
	    if(*armor==0){
	        printf("B. Armor(+10 HP)\n");
	    }
	    else{
	        printf("B. Extra life\n");
	    }
		printf("Gold cost: 20\n");
		printf("C. Life Potion(restores health)\n");
		printf("Gold cost: 30\n");
		scanf(" %c", &prompt);
		if (prompt == 'A' || prompt == 'a') {
			if (*sword != 1 && *gold >= 10) {
				printf("You have purchased the sword\n");
				*sword = 1;
				*gold-=10;
			}
			else if(*gold >=10){
			    printf("You have purchased the lootbox\n");
			    int itemR = GetRandomNum(4, 0);
			    if(itemR == 0){
			        printf("You received a potion from the lootbox!\n");
			        *potions+=1;
			    }
			    else if(itemR == 1){
			        printf("You received an extra life from the lootbox!\n");
			        *lives+=1;
			    }
			    else{
			        printf("Guess you weren't that lucky! You received nothing from the lootbox! ;(\n");
			    }
			    *gold-=10;
			}
			else {
				printf("You do not have enough gold!\n");
			}
		}
		else if (prompt == 'B' || prompt == 'b') {
		        if(*gold >=20 && *armor !=1){
				    printf("You have purchased armor\n");
				    *gold-=20;
				    *armor = 1;
		        }
		        else if(*gold >= 20){
		            printf("You have purchased an extra life\n");
		            *lives+=1;
		            *gold-=20;
		        }
		        else{
		            printf("You do not have enough gold!\n");
		        }
		}
		else if (prompt == 'C' || prompt == 'c') {
		    if(*gold >= 30){
			    printf("You have purchased the potion and your health is fully restored\n");
			    *potions+=1;
			    *gold-=30;
		    }
		    else{
		        printf("You do not have enough gold!\n");
		    }
		}
		if(*gold < 10){
	        printf("You are too broke to buy anything. Come back when you have more money.\n");
	        printf("You left with %d gold.\n", *gold);
	    }
	    else{
	        printf("Enter 'q' to quit.\n");
	    }
		printf("\n");
	}
	return *gold;
}

int DamageToMonsters(int damageType, enemy enemyType, int sword) {
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


	if (damageType == 2) {
			if (strcmp(enemyType.element, "Fire")) {

				monsterDamage = 40;
			}
			else {
				monsterDamage = 20;
			}
		}


	if (damageType == 3) {
			if (strcmp(enemyType.element, "Air")) {

				monsterDamage = 40;
			}
			else {
				monsterDamage = 20;
			}
		}


	if (damageType == 4) {
			if (strcmp(enemyType.element, "Earth")) {

				monsterDamage = 40;
			}
			else {
				monsterDamage = 20;
			}
		}
	}
	else {
		printf("Need to enter a valid attack type like Fire(F), Water(W), Earth(E) or Air(A)!");
	}

	if (sword == 1) {
			monsterDamage += 10;
		}
		return monsterDamage;

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



void FirstPath(int pathChoice){
  if (pathChoice == 1){
    printf("You have chosen Left");
  }
  else if(pathChoice == 2){
    printf("You have chosen Center");
  }
  else if(pathChoice ==3){
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


//Print attack elements fire, water, earth, air and get userInput choice
void GetAndPrintUserAttackElementChoice(int *elementChoice){

  int elementNum=4;
  int minNum = 1;


  scanf("%d", elementChoice);
  
  while ( *elementChoice >elementNum || *elementChoice <1){
        printf("******ERROR*****\n");
        printf("You have selected %d which is out of range, please select an attack item between 1 and 4\n", *elementChoice);
        //PrintAttackElements();
        scanf("%d", elementChoice);
        printf("\n");
  }
      printf("\n");
      printf("element choice: %d", *elementChoice);

  PrintAttackElements(minNum, elementNum);

  GetValidateUserInputDigit(elementChoice, minNum, elementNum);
  printf("my new element %d\n", *elementChoice);
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
