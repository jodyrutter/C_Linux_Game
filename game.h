#ifndef game_h
#define game_h
typedef struct enemy_struct{
	char tunnelHint[100];
	char name[50];
	char element[50];
	char startingPrompt[999];
	char asciiArt[50][200];
} enemy;




void PopulateEnemies(enemy enemies[]);
int SetDifficulty(int userDif);
int GetRandomPathNum(int numOfPaths);
void PrintPath(int firstPath);
#endif