#include "Classes.h"

void MakeWorld() {
	float WorldLength,WorldWidth,Speed;
	cout<<"Please input the Length of the World:";
	cin>>WorldLength;
	cout<<"Please input the Width of the World:";
	cin>>WorldWidth;
	cout<<"Please input Tank's speed(default by 1)£º";
	cin>>Speed;
	L = WorldLength;
	W = WorldWidth;
	World World1(WorldLength,WorldWidth,Speed);
}

int ChooseGameMode() {
	cout<<"Choose the game mode: 1.Read movement from file    2¡¢KeyboardControl(Not Avaliable)"<<endl;
	int GameMode;
	cin>>GameMode;
	return GameMode;
}

double random(double start, double end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}