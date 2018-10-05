#pragma once
#include "../Player.h"
#include <string>

class SimpleBot : public Player {
public:
	static std::string id;
	SimpleBot();
	virtual void Play(double, TankControl *);
	virtual ~SimpleBot();
};
