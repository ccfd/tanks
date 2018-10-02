#pragma once
#include "../Player.h"

class SimpleBot : public Player {
public:
	SimpleBot();
	virtual void Play(double, TankControl *);
	virtual ~SimpleBot();
};
