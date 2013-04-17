#pragma once
#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

//Game Setting ----------------------------------------
const float DefaultTankWidth = 2;
const int BulletX = 5;
const int BulletDamage = 34;
const float FlashRate = 100;    //Higher value Smoother picture, and more system resouce cost
//-----------------------------------------------------

ifstream ReadCommand;
int Stack[20];
int *StackPointer = Stack;
char Tank1Command[300];
char Tank2Command[300];
float OneStep;

static float L = 0;
static float W = 0;
int DefineTank1Event = 0;
int DefineTank2Event = 0;

static double Counter = 0;

int Pointer4Tank1Command = 0;
int Pointer4Tank2Command = 0;

bool GameOver = false;

struct Position
{
	float x,y;
};

class pushClass
{
public:
	void operator<< (int ReadyForStack) {
		*StackPointer = ReadyForStack;
		*StackPointer = *StackPointer + 1;
	}
};
pushClass push;

class popClass
{
public:
	void operator>> (int &ReceiveFromStack) {
		*StackPointer = *StackPointer - 1;
		ReceiveFromStack = *StackPointer;
	}
};
popClass pop;

class World
{
public:
	World(float Length,float Width,float Speed);
	float Length,Width;
private:
	float Speed;
};

class Bullet;
Bullet *Bullet1;
Bullet *Bullet2;

class Tank
{
public:
	Tank(void);
	~Tank(void);
	void SetName(int a);
	void TankUp();
	void TankDown();
	void TankLeft();
	void TankRight();
	void TankMoveStraight();
	void TankTurn(float );
	virtual void TankBeShot(Bullet *);
	virtual void TankCheckPosition();
	bool FireStatus;
	Position TankPosition;
	float Width;
protected:
	void TankDead();
	int Name,HP,WHU_P,WHD_P,WHL_P,WHR_P,WF_P;
	float Angle;
	bool DuringEvent;
};

class TankNo1 : public Tank {
public:
	void Init() {
		this->TankPosition.x = 90;
		this->TankPosition.y = 90;
	}
	int GetCommand();
	void TankRunCommand();
	void TankCheckPosition();
	void TankFire();
	void TankBeShot(Bullet *);
};

class TankNo2 : public Tank {
public:
	void Init() {
		this->TankPosition.x = 10;
		this->TankPosition.y = 10;
	}
	int GetCommand();
	void TankRunCommand();
	void TankCheckPosition();
	void TankFire();
	void TankBeShot(Bullet *);
};

class Bullet
{
public:
	Bullet(Tank &,float ,Position );
	~Bullet();
	void BulletDoDamege(Tank &);
	bool BulletMove(Tank &);
	int Damege;
private:
	Position BulletPosition;
	Tank &FiredPlayer;
	float BulletAngle;
};

TankNo1 A;
TankNo2 B;