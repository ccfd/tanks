#include "Bot.h"
#include <math.h>

namespace MyNamespace {

RegisterPlayer< BotPlayer > BotPlayer::id("SimpleBot");

BotPlayer::BotPlayer(void)
{

}

void BotPlayer::Play(double time, TankControl* control) {
	double left, right, turn=0, lift=0;
	left = 25*sin(time);
	right = 25;
	for (Sights::iterator it = control->sights.begin(); it != control->sights.end(); it++) {
		if (it->tag == TAG_ENEMY) {
			control->ShootGun();
		}
	}
	control->ShootCannon();
	control->SetEngines(left, right, turn, lift);
}

BotPlayer::~BotPlayer(void)
{

}

}

