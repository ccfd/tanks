#pragma once

class LiveTank;

class TankControl
{
	friend LiveTank;
	bool canShootGun, canShootCannon;
	bool wannaShootGun, wannaShootCannon;
	int cannonAmmunition, gunAmmunition;
	double left, right, turn, lift;
	double headAngle, cannonAngle,azimuth;
public:
	TankControl();
	bool CanShootGun();
	void ShootGun();
	bool CanShootCannon();
	void ShootCannon();
	void SetEngines(double, double, double, double);
	double GetAzimuth();
	double GetHeadAngle();
	double GetCannonAngle();
	int GetCannonAmmunition();
	int GetGunAmmunition();
	~TankControl();
};
