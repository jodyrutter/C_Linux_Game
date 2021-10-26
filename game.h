#ifndef game_h
#define game_h
typedef struct enemy_struct{
	char tunnelHint[100];
	char name[50];
	char element[50];
	char startingPrompt[999];
	char asciiArt[50][200];
} enemy;




int PopulateEnemies(enemy enemies[], int max_size);
void GetIntroductionInfo(char userName[], int *userDifficulty, int *monsterDamage);
void GetUserPathChoise(int *pathChoise);
void FirstPath(int pathChoise);
// void PopulateEnemies(enemy enemies[]);
int SetDifficulty(int userDif);
int GetRandomNum(int numUpTo, int startAtNum);
void PrintPath(int firstPath);

void PrintAttackElements();
void GetUserAttackElementChoise(int* elementChoise);
#endif