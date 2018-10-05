#pragma once
#include "TankControl.h"
#include <string>

class Player
{
public:
	Player();
	virtual void Play(double, TankControl*);
	virtual ~Player();
};

#include "Factory.h"
