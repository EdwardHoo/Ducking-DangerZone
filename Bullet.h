#include "Classes.h"

void Bullet::BulletDoDamege(Tank &TargetTank) {
	TargetTank.TankBeShot(this);
}

bool Bullet::BulletMove(Tank &Tango) {
	float Tan = tan(((BulletAngle * 3.1415926) / 180));
	this->BulletPosition.x += 1 * OneStep;
	this->BulletPosition.y += 1 * (OneStep * Tan);
	if(BulletPosition.x <= 0) {
		cout<<"子弹击中左壁。";
		return true;
	}
	if(BulletPosition.y <= 0) {
		cout<<"子弹击中下壁。";
		return true;
	}
	if(BulletPosition.x >= L) {
		cout<<"子弹击中右壁。";
		return true;
	}
	if(BulletPosition.y >= W) {
		cout<<"子弹击中上壁。";
		return true;
	}
	if(BulletPosition.x >= Tango.TankPosition.x - Tango.Width&&BulletPosition.x <= Tango.TankPosition.x + Tango.Width&&
	   BulletPosition.y >= Tango.TankPosition.y - Tango.Width&&BulletPosition.y <= Tango.TankPosition.y + Tango.Width) {
		this->BulletDoDamege(Tango);
		return true;
	}
	return false;
}