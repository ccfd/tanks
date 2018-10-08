#pragma once
#include "Player.h"

class KeyboardPlayer : public Player {
public:
	static std::string id;
	KeyboardPlayer();
	virtual void Play(double, TankControl *);
	virtual ~KeyboardPlayer();
};
