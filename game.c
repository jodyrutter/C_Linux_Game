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

int GetRandomPathNum(numOfPaths){
  int myPathNum;
  time_t t;
  srand((unsigned) time(&t)); //unique seed
  myPathNum = (rand() % 4)+1; //Get random numbers 1-4
  return myPathNum;
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
	ssize_t read; //Variable to determine if end of file is reached.
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