#include "TankControl.h"

TankControl::TankControl() {
	canShootGun = false;
	canShootCannon = false;
	wannaShootGun = false;
	wannaShootCannon = false;
	left = right = turn = lift = 0;
}

bool TankControl::CanShootGun() {
	return canShootGun;
}

void TankControl::ShootGun() {
	wannaShootGun = true;
}

bool TankControl::CanShootCannon() {
	return canShootCannon;
}

void TankControl::ShootCannon() {
	wannaShootCannon = true;
}

void TankControl::SetEngines(double left_, double right_, double turn_, double lift_) {
	left=left_;
	right=right_;
	turn=turn_;
	lift=lift_;
}

double TankControl::GetAzimuth() {
	return azimuth;
}

double TankControl::GetHeadAngle() {
	return headAngle;
}

double TankControl::GetCannonAngle() {
	return cannonAngle;
}

int TankControl::GetCannonAmmunition() {
	return cannonAmmunition;
}

int TankControl::GetGunAmmunition() {
	return gunAmmunition;
}

TankControl::~TankControl(void)
{

}
