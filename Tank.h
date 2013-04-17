#include "Classes.h"

Tank::Tank(void):HP(100),Angle(0),FireStatus(true),Width(DefaultTankWidth),DuringEvent(false) {

}

Tank::~Tank(void) {

}

void Tank::SetName(int a) {
	this->Name = a;
} 

void Tank::TankUp() {
	TankPosition.y += OneStep;
	this->TankCheckPosition();
}

void Tank::TankDown() {
	TankPosition.y -= OneStep;
	this->TankCheckPosition();
}

void Tank::TankLeft() {
	TankPosition.x -= OneStep;
	this->TankCheckPosition();
}

void Tank::TankRight() {
	TankPosition.x += OneStep;
	this->TankCheckPosition();
}

void Tank::TankMoveStraight() {
	float Tan = tan(((Angle * 3.1415926) / 180));
	this->TankPosition.x += OneStep;
	this->TankPosition.y += (OneStep * Tan);
	this->TankCheckPosition();
}

void Tank::TankTurn(float Angle) {
	this->Angle += Angle;
}

void Tank::TankBeShot(Bullet *) {}

void Tank::TankCheckPosition() {}

void Tank::TankDead() {
	GameOver = true;
	this->~Tank();
}

void TankNo1::TankCheckPosition() {
	//Check whether hit the enemy
	if((B.TankPosition.x - TankPosition.x) >= 0&&(B.TankPosition.x - TankPosition.x) <= 2 * DefaultTankWidth&&(B.TankPosition.y - TankPosition.y) >= 0&&(B.TankPosition.y - TankPosition.y) <= 2 * DefaultTankWidth) {
		   TankPosition.x = B.TankPosition.x - 2 * DefaultTankWidth;
		   TankPosition.y = B.TankPosition.y - 2 * DefaultTankWidth;
	}else if((TankPosition.x - B.TankPosition.x) >= 0&&(TankPosition.x - B.TankPosition.x) <= 2 * DefaultTankWidth&&(B.TankPosition.y - TankPosition.y) >= 0&&(B.TankPosition.y - TankPosition.y) <= 2 * DefaultTankWidth) {
		   TankPosition.x = B.TankPosition.x + 2 * DefaultTankWidth;
		   TankPosition.y = B.TankPosition.y - 2 * DefaultTankWidth;
	}else if((TankPosition.x - B.TankPosition.x) >= 0&&(TankPosition.x - B.TankPosition.x) <= 2 * DefaultTankWidth&&(TankPosition.y - B.TankPosition.y) >= 0&&(TankPosition.y - B.TankPosition.y) <= 2 * DefaultTankWidth) {
		   TankPosition.x = B.TankPosition.x + 2 * DefaultTankWidth;
		   TankPosition.x = B.TankPosition.x + 2 * DefaultTankWidth;
	}else if((B.TankPosition.x - TankPosition.x) >= 0&&(B.TankPosition.x - TankPosition.x) <= 2 * DefaultTankWidth&&(TankPosition.y - B.TankPosition.y) >= 0&&(TankPosition.y - B.TankPosition.y) <= 2 * DefaultTankWidth) {
		   TankPosition.x = B.TankPosition.x - 2 * DefaultTankWidth;
		   TankPosition.x = B.TankPosition.x + 2 * DefaultTankWidth;
	}
	//Check whether hit the edge
	if(TankPosition.x <= 0) {
		TankPosition.x = 0;
		if(WHL_P) {
			push<<Pointer4Tank1Command + 1;
			Pointer4Tank1Command = this->WHL_P - 1;
			this->DuringEvent = true;
		}
	}
	if(TankPosition.y <= 0) {
		TankPosition.y = 0;
		if(WHD_P) {
			push<<Pointer4Tank1Command + 1;
			Pointer4Tank1Command = this->WHD_P - 1;
			this->DuringEvent = true;
		}
	}
	if(TankPosition.x >= L) {
		TankPosition.x = L;
		if(WHR_P) {
			push<<Pointer4Tank1Command + 1;
			Pointer4Tank1Command = this->WHR_P - 1;
			this->DuringEvent = true;
		}
	}
	if(TankPosition.y >= W) {
		TankPosition.y = W;
		if(WHU_P) {
			push<<Pointer4Tank1Command + 1;
			Pointer4Tank1Command = this->WHU_P - 1;
			this->DuringEvent = true;
		}
	}
}

void TankNo1::TankFire() {
	if(this->FireStatus) {
		Bullet1 = new  Bullet(*this,Angle,this->TankPosition);
		cout<<"Tank1 Fired! "<<endl;
		FireStatus = false;
	}
}

void TankNo1::TankBeShot(Bullet *BulletPointer) {
	this->HP -= BulletPointer->Damege;
	if(this->HP <= 0) {
		cout<<"After "<<Counter<<" times of fires, Tank"<<this->Name<<" was KILLED."<<endl;
		this->TankDead();
	}
	if(WF_P) {
		push<<Pointer4Tank1Command;
		Pointer4Tank1Command = WF_P;
	}
}

void TankNo2::TankCheckPosition() {
	//Check whether hit the enemy
	if((A.TankPosition.x - TankPosition.x) >= 0&&(A.TankPosition.x - TankPosition.x) <= 2 * DefaultTankWidth&&(A.TankPosition.y - TankPosition.y) >= 0&&(A.TankPosition.y - TankPosition.y) <= 2 * DefaultTankWidth) {
		   TankPosition.x = A.TankPosition.x - 2 * DefaultTankWidth;
		   TankPosition.y = A.TankPosition.y - 2 * DefaultTankWidth;
	}else if((TankPosition.x - A.TankPosition.x) >= 0&&(TankPosition.x - A.TankPosition.x) <= 2 * DefaultTankWidth&&(A.TankPosition.y - TankPosition.y) >= 0&&(A.TankPosition.y - TankPosition.y) <= 2 * DefaultTankWidth) {
		   TankPosition.x = A.TankPosition.x + 2 * DefaultTankWidth;
		   TankPosition.y = A.TankPosition.y - 2 * DefaultTankWidth;
	}else if((TankPosition.x - A.TankPosition.x) >= 0&&(TankPosition.x - A.TankPosition.x) <= 2 * DefaultTankWidth&&(TankPosition.y - A.TankPosition.y) >= 0&&(TankPosition.y - A.TankPosition.y) <= 2 * DefaultTankWidth) {
		   TankPosition.x = A.TankPosition.x + 2 * DefaultTankWidth;
		   TankPosition.x = A.TankPosition.x + 2 * DefaultTankWidth;
	}else if((A.TankPosition.x - TankPosition.x) >= 0&&(A.TankPosition.x - TankPosition.x) <= 2 * DefaultTankWidth&&(TankPosition.y - A.TankPosition.y) >= 0&&(TankPosition.y - A.TankPosition.y) <= 2 * DefaultTankWidth) {
		   TankPosition.x = A.TankPosition.x - 2 * DefaultTankWidth;
		   TankPosition.x = A.TankPosition.x + 2 * DefaultTankWidth;
	}
	//Check whether hit the edge
	if(TankPosition.x < 0) {
		TankPosition.x = 0;
		if(WHL_P) {
			push<<Pointer4Tank2Command;
			Pointer4Tank2Command = this->WHL_P - 1;
			this->DuringEvent = true;
		}
	}
	if(TankPosition.y < 0) {
		TankPosition.y = 0;
		if(WHD_P) {
			push<<Pointer4Tank2Command;
			Pointer4Tank2Command = this->WHD_P - 1;
			this->DuringEvent = true;
		}
	}
	if(TankPosition.x > L) {
		TankPosition.x = L;
		if(WHR_P) {
			push<<Pointer4Tank2Command;
			Pointer4Tank2Command = this->WHR_P - 1;
			this->DuringEvent = true;
		}
	}
	if(TankPosition.y > W) {
		TankPosition.y = W;
		if(WHU_P) {
			push<<Pointer4Tank2Command;
			Pointer4Tank2Command = this->WHU_P - 1;
			this->DuringEvent = true;
		}
	}
}

void TankNo2::TankFire() {
	if(this->FireStatus) {
		Bullet2 = new Bullet(*this,Angle,this->TankPosition);
		cout<<"Tank2 Fired! "<<endl;
		FireStatus = false;
	}
}

void TankNo2::TankBeShot(Bullet *BulletPointer) {
	this->HP -= BulletPointer->Damege;
	if(this->HP <= 0) {
		cout<<"After "<<Counter<<" times of fires, Tank"<<this->Name<<" was KILLED."<<endl;
		this->TankDead();
	}
	if(WF_P) {
		push<<Pointer4Tank2Command;
		Pointer4Tank2Command = WF_P;
	}
}

int TankNo1::GetCommand() {
	ReadCommand.open("Tank1.ini",ios::in|ios::_Nocreate);
	if(!ReadCommand) {
		cerr<<"Big Error!";
		exit(1);
	}
	bool Evt = false;
	bool Def = false;
	for(int i = 0;ReadCommand.eof() == 0;i++) {
		ReadCommand>>Tank1Command[i];
		if(Tank1Command[i] == 0) {
			break;
		}
		if(Tank1Command[i] == 58&&Evt == false) {
			Evt = true;
			continue;
		}else if(Tank1Command[i] == 58&&Evt == true) {
			Evt = false;
			Def = false;
			continue;
		}
		if(Evt&&Def == false) {
			Def = true;
			switch ((int)Tank1Command[i])
			{
			case 76:
				this->WHL_P = i + 1;
				break;
			case 108:
				this->WHL_P = i + 1;
				break;
			case 82:
				this->WHR_P = i + 1;
				break;
			case 114:
				this->WHR_P = i + 1;
				break;
			case 85:
				this->WHU_P = i + 1;
				break;
			case 117:
				this->WHU_P = i + 1;
				break;
			case 68:
				this->WHD_P = i + 1;
				break;
			case 100:
				this->WHD_P = i + 1;
				break;
			case 70:
				this->WF_P = i + 1;
				break;
			case 102:
				this->WF_P = i + 1;
				break;
			default:
				cerr<<"Fail to get the Tank's movement, go check Ur Tank*.ini";
				exit(1);
				break;
			}
		}
	}
	ReadCommand.close();
}

int TankNo2::GetCommand() {
	ReadCommand.open("Tank2.ini",ios::in|ios::_Nocreate);
	if(!ReadCommand) {
		cerr<<"Fail to open Tank*.ini!";
		exit(1);
	}
	bool Evt = false;
	bool Def = false;
	for(int i = 0;ReadCommand.eof() == 0;i++) {
		ReadCommand>>Tank2Command[i];
		if(Tank2Command[i] == 0) {
			break;
		}
		if(Tank2Command[i] == 58&&Evt == false) {
			Evt = true;
			continue;
		}else if(Tank2Command[i] == 58&&Evt == true) {
			Evt = false;
			Def = false;
			continue;
		}
		if(Evt&&Def == false) {
			Def = true;
			switch ((int)Tank2Command[i])
			{
			case 76:
				this->WHL_P = i + 1;
				break;
			case 108:
				this->WHL_P = i + 1;
				break;
			case 82:
				this->WHR_P = i + 1;
				break;
			case 114:
				this->WHR_P = i + 1;
				break;
			case 85:
				this->WHU_P = i + 1;
				break;
			case 117:
				this->WHU_P = i + 1;
				break;
			case 68:
				this->WHD_P = i + 1;
				break;
			case 100:
				this->WHD_P = i + 1;
				break;
			case 70:
				this->WF_P = i + 1;
				break;
			case 102:
				this->WF_P = i + 1;
				break;
			default:
				cerr<<"Fail to get Tank's movement, check Ur code(Event grammar)";
				exit(1);
				break;
			}
		}
	}
	ReadCommand.close();
}

void TankNo1::TankRunCommand() {
	if((int)Tank1Command[Pointer4Tank1Command] == 85||
	   (int)Tank1Command[Pointer4Tank1Command] == 117) {
		this->TankUp();
		Pointer4Tank1Command += 1;
	}else if((int)Tank1Command[Pointer4Tank1Command] == 68||
			 (int)Tank1Command[Pointer4Tank1Command] == 100) {
		this->TankDown();
		Pointer4Tank1Command += 1;
	}else if((int)Tank1Command[Pointer4Tank1Command] == 76||
	         (int)Tank1Command[Pointer4Tank1Command] == 108) {
		this->TankLeft();
		Pointer4Tank1Command += 1;
	}else if((int)Tank1Command[Pointer4Tank1Command] == 82||
		     (int)Tank1Command[Pointer4Tank1Command] == 114) {
		this->TankRight();
		Pointer4Tank1Command += 1;
	}else if((int)Tank1Command[Pointer4Tank1Command] == 70||
		     (int)Tank1Command[Pointer4Tank1Command] == 102) {
		this->TankFire();
		Pointer4Tank1Command += 1;
	}else if((int)Tank1Command[Pointer4Tank1Command] == 83||
			 (int)Tank1Command[Pointer4Tank1Command] == 115) {
		this->TankMoveStraight();
		Pointer4Tank1Command += 1;
	}else if((int)Tank1Command[Pointer4Tank1Command] == 84||
		     (int)Tank1Command[Pointer4Tank1Command] == 116) {
		Pointer4Tank1Command += 2;
		int Temp = 0;
		for(;(int)(Tank1Command[Pointer4Tank1Command]) >= 48&&(int)(Tank1Command[Pointer4Tank1Command]) <= 57;) {
			Pointer4Tank1Command ++;
			Temp++;
		}
		int TempAngle = 0;
		int NewTemp = Temp;
		for(;Temp != 0;Temp--) {
			TempAngle += ((Tank1Command[Pointer4Tank1Command - NewTemp + Temp - 1]) - 48) * pow(10,NewTemp - Temp);
		}
		this->TankTurn(TempAngle);
	}else if((int)Tank1Command[Pointer4Tank1Command] == 58) {
		Pointer4Tank1Command = 0;
	}else {
		cout<<"Wrong command, force exit. Error Code:"<<this->Name<<(int)Tank1Command[Pointer4Tank1Command]<<Pointer4Tank1Command<<"";
		exit(1);
	}

	if((int)Tank1Command[Pointer4Tank1Command] == 58&&this->DuringEvent == true) {
		pop>>Pointer4Tank1Command;
		this->DuringEvent = false;
	}

	if((int)Tank1Command[Pointer4Tank1Command] == 0) {
		Pointer4Tank1Command = 0;
	}
}

void TankNo2::TankRunCommand() {
	if((int)Tank2Command[Pointer4Tank2Command] == 85||
	   (int)Tank2Command[Pointer4Tank2Command] == 117) {
		this->TankUp();
		Pointer4Tank2Command += 1;
	}else if((int)Tank2Command[Pointer4Tank2Command] == 68||
			 (int)Tank2Command[Pointer4Tank2Command] == 100) {
		this->TankDown();
		Pointer4Tank2Command += 1;
	}else if((int)Tank2Command[Pointer4Tank2Command] == 76||
	         (int)Tank2Command[Pointer4Tank2Command] == 108) {
		this->TankLeft();
		Pointer4Tank2Command += 1;
	}else if((int)Tank2Command[Pointer4Tank2Command] == 82||
		     (int)Tank2Command[Pointer4Tank2Command] == 114) {
		this->TankRight();
		Pointer4Tank2Command += 1;
	}else if((int)Tank2Command[Pointer4Tank2Command] == 70||
		     (int)Tank2Command[Pointer4Tank2Command] == 102) {
		this->TankFire();
		Pointer4Tank2Command += 1;
	}else if((int)Tank2Command[Pointer4Tank2Command] == 83||
			 (int)Tank2Command[Pointer4Tank2Command] == 115) {
		this->TankMoveStraight();
		Pointer4Tank2Command += 1;
	}else if((int)Tank2Command[Pointer4Tank2Command] == 84||
		     (int)Tank2Command[Pointer4Tank2Command] == 116) {
		Pointer4Tank2Command += 2;
		int Temp = 0;
		for(;(int)Tank2Command[Pointer4Tank2Command] >= 48&&(int)Tank2Command[Pointer4Tank2Command] <= 57;) {
			Pointer4Tank2Command ++;
			Temp++;
		}
		int TempAngle = 0;
		int NewTemp = Temp;
		for(;Temp != 0;Temp--) {
			TempAngle += (Tank2Command[Pointer4Tank2Command - NewTemp + Temp - 1] - 48) * pow(10,NewTemp - Temp);
		}
		this->TankTurn(TempAngle);
	}else if((int)Tank2Command[Pointer4Tank2Command] == 58) {
		Pointer4Tank2Command = 0;
		this->DuringEvent = false;
	}else {
		cout<<"Wrong command, force exit. Error Code:"<<this->Name<<(int)Tank2Command[Pointer4Tank2Command]<<Pointer4Tank2Command<<"";
		exit(1);
	}

	if((int)Tank2Command[Pointer4Tank2Command] == 58&&this->DuringEvent == true) {
		pop>>Pointer4Tank2Command;
	}

	if((int)Tank2Command[Pointer4Tank2Command] == 0) {
		Pointer4Tank2Command = 0;
	}
}
