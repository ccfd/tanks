#include "SimpleBot.h"
#include <math.h>

namespace SimpleBot {

std::string SimpleBot::id = "SimpleBot";

SimpleBot::SimpleBot(void)
{

}

void SimpleBot::Play(double time, TankControl* control) {
	double left, right, turn=0, lift=0;
	left = 25*sin(time);
	right = 25;
	control->ShootCannon();
	control->ShootGun();
	control->SetEngines(left, right, turn, lift);
}

SimpleBot::~SimpleBot(void)
{

}

}

template class PlayerFactory::Register < SimpleBot::SimpleBot >;
