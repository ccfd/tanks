#include "Player.h"
#include <math.h>

Player::Player()
{

}

void Player::PlayAll(double time, std::vector<TankControl*>& vec) {
	for (std::vector<TankControl*>::iterator it = vec.begin(); it != vec.end(); it++) {
		this->Play(time, *it);
	}
}

void Player::Play(double time, TankControl* control) {

}

void Player::Result(double myPoints, double otherPoints) {

}

Player::~Player()
{

}
