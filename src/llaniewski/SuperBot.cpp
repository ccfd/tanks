#include "SuperBot.h"
#include <math.h>

namespace llaniewski {

std::string SuperBot::id = "llaniewski";

SuperBot::SuperBot(void)
{

}

void SuperBot::Play(double time, TankControl* control) {
	double left, right, turn=0, lift=0;
	left = 25*sin(time);
	right = 25;
	control->ShootCannon();
	control->ShootGun();
	control->SetEngines(left, right, turn, lift);
}

SuperBot::~SuperBot(void)
{

}

} // end of namespace

template class PlayerFactory::Register < llaniewski::SuperBot >;
