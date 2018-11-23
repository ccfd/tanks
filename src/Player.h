#pragma once
#include "TankControl.h"
#include <string>

class Player
{
public:
	Player();
	virtual void Play(double, TankControl*);
	virtual void PlayAll(double, std::vector<TankControl*>&);
	virtual void Result(double, double);
	virtual ~Player();
};

#include "Factory.h"
