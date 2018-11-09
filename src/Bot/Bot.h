#pragma once
#include "../Player.h"
#include <string>

namespace MyNamespace {

class BotPlayer : public Player {
public:
	static RegisterPlayer< BotPlayer > id;
	BotPlayer();
	virtual void Play(double, TankControl *);
	virtual ~BotPlayer();
};

}