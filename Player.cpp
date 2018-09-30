#include "Player.h"
#include "math.h"

Player::Player()
{
}

void Player::Play(double time, TankControl* control) {
// Just turn and shoot as hell
	control->ShootGun();
	control->ShootCannon();
	control->SetEngines(25*sin(time), 20, 0, 0);
}

Player::~Player()
{
}
