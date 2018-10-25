#pragma once
#include "../Player.h"
#include <string>

namespace SimpleBot {

class SimpleBot : public Player {
public:
	static RegisterPlayer< SimpleBot > id;
	SimpleBot();
	virtual void Play(double, TankControl *);
	virtual ~SimpleBot();
};

}