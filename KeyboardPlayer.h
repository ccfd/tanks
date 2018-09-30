#pragma once
#include "Player.h"

class KeyboardPlayer : public Player {
public:
	KeyboardPlayer();
	virtual void Play(double, TankControl *);
	virtual ~KeyboardPlayer();
};
