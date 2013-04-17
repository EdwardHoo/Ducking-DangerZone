#include "Classes.h"

World::World(float Length,float Width,float Speed) {
	cout<<"Making World......"<<endl;
	this->Length = Length;
	this->Width = Width;
	this->Speed = Speed;
	OneStep = Speed / FlashRate;
	cout<<"Done!"<<endl;
}