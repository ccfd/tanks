#include "Player.h"
#include "math.h"

Player::Player(void)
{
}

void Player::Play(double t, TankControl* control) {
	control->ShootGun();
	control->ShootCannon();
	control->SetEngines(25*sin(t), 20*sin(t), 1, 0);
}

Player::~Player(void)
{
}
