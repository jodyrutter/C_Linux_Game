#ifndef game_h
#define game_h
typedef struct enemy_struct{
	char tunnelHint[100]; //This hint is displayed to the users when choosing a tunnel. Ex. There is a glistening light coming from this tunnel.
	char name[50]; //The name of the enemy. Ex. Dragon
	char element[50]; //The element associated with the enemy. Ex. Fire
	char startingPrompt[999]; //The prompt given to the user when they enter a tunnel.
	char asciiArt[50][200]; //The ascii art of the enemy.
} enemy;




void PopulateEnemies(enemy enemies[]);
int SetDifficulty(int userDif);
int GetRandomNum(int numUpTo, int startAtNum);
void PrintPath(int firstPath);
#endif