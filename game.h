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
void PrintEnemyPrompts(int enemyNum, enemy enemies[]);
int SetDifficulty(int userDif);
int GetRandomNum(int numUpTo, int startAtNum);
void PrintPaths(int monster1, int monster2, int monster3, enemy enemies[], int numEnemies);
#endif
