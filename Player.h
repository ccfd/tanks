#pragma once
#include "TankControl.h"

class Player
{
public:
	Player(void);
	virtual void Play(double, TankControl*);
	virtual ~Player(void);
};
