#include "Classes.h"

void Bullet::BulletDoDamege(Tank &TargetTank) {
	TargetTank.TankBeShot(this);
}

bool Bullet::BulletMove(Tank &Tango) {
	float Tan = tan(((BulletAngle * 3.1415926) / 180));
	this->BulletPosition.x += 1 * OneStep;
	this->BulletPosition.y += 1 * (OneStep * Tan);
	if(BulletPosition.x <= 0) {
		return true;
	}
	if(BulletPosition.y <= 0) {
		return true;
	}
	if(BulletPosition.x >= L) {
		return true;
	}
	if(BulletPosition.y >= W) {
		return true;
	}
	if(BulletPosition.x >= Tango.TankPosition.x - Tango.Width&&BulletPosition.x <= Tango.TankPosition.x + Tango.Width&&
	   BulletPosition.y >= Tango.TankPosition.y - Tango.Width&&BulletPosition.y <= Tango.TankPosition.y + Tango.Width) {
		this->BulletDoDamege(Tango);
		return true;
	}
	return false;
}
