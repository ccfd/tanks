#pragma once
#include "TankControl.h"
#include <string>

class Player
{
public:
	Player();
	virtual void Play(double, TankControl*);
	virtual void PlayAll(double, std::vector<TankControl*>&);
	virtual ~Player();
};

#include "Factory.h"
