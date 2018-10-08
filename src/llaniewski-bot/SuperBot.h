#pragma once
#include "../Player.h"
#include <string>

namespace llaniewski_bot {

class SuperBot : public Player {
public:
	static std::string id;
	SuperBot();
	virtual void Play(double, TankControl *);
	virtual ~SuperBot();
};

}