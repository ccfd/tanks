#pragma once
#include "TankControl.h"

class Player
{
public:
	Player();
	virtual void Play(double, TankControl*);
	virtual ~Player();
};
