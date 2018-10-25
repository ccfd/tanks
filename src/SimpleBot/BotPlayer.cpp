#include "BotPlayer.h"
#include <math.h>

namespace SimpleBot {

RegisterPlayer< BotPlayer > BotPlayer::id("SimpleBot");

BotPlayer::BotPlayer(void)
{

}

void BotPlayer::Play(double time, TankControl* control) {
	double left, right, turn=0, lift=0;
	left = 25*sin(time);
	right = 25;
	control->ShootCannon();
	control->ShootGun();
	control->SetEngines(left, right, turn, lift);
}

BotPlayer::~BotPlayer(void)
{

}

}

