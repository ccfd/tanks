#include "TankControl.h"

const int Sights::resolution = 81;
const double Sights::alpha = 1;

Sights::Sights() : std::vector< Pixel >(resolution) {
	for (int i = 0; i < resolution; i++) {
		(*this)[i].angle = alpha * i / (resolution - 1) - alpha / 2;
	}
};

TankControl::TankControl() {
	Init();
}

void TankControl::Init() {
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

double TankControl::GetHP() {
	return hp;
}

int TankControl::GetID() {
	return id;
}

TankControl::~TankControl(void)
{

}
