#pragma once
#include "Player.h"

class KeyboardPlayer : public Player {
public:
	static RegisterPlayer < KeyboardPlayer > id;
	KeyboardPlayer();
	virtual void Play(double, TankControl *);
	virtual ~KeyboardPlayer();
};
