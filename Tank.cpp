#include "stdafx.h"
#include "Header.h"

using namespace std;

int main(int argc,char **argv)
{
	MakeWorld();
begin:
	if(ChooseGameMode() == 1) {
		A.Init();
		B.Init();
		A.SetName(1);
		B.SetName(2);
		A.GetCommand();
		B.GetCommand();
		for(;!GameOver;) {
			cout<<"A:("<<A.TankPosition.x<<","<<A.TankPosition.y<<") B:("<<B.TankPosition.x<<","<<B.TankPosition.y<<")"<<endl;			
			for(int i = 0; i < FlashRate; i++) {
				A.TankRunCommand();
			}
			for(int i = 0; i < BulletX * FlashRate; i++) {
				if(!A.FireStatus) {
					if(Bullet1->BulletMove(B)) {
						Bullet1->~Bullet();
					}
				}
			}
			for(int i = 0; i < FlashRate; i++) {
				B.TankRunCommand();
			}
			for(int i = 0; i < BulletX * FlashRate; i++) {
				if(!B.FireStatus) {
					if(Bullet2->BulletMove(A)) {
						Bullet2->~Bullet();
					}
				}
			}
			//Sleep(500);
			Counter++;
		}
	}else {
		cout<<"Sorry, this part is still being writting, press Enter to return;"<<endl;
		cin.get();
		cin.get();
		system("cls");
		goto begin;
	}
	return 0;
}