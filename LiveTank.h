#pragma once
#include "Object.h"
#include "TankAvatar.h"

class LiveTank : public Object {
	TankAvatar avatar;
	double x,y,rb,rh,t;
	int i;
	double ran;
public:
	LiveTank (double x_, double y_, double rb_, double rh_);
	~LiveTank ();
	virtual void Draw(sf::RenderWindow* window);
	virtual void Tick(App* app);
	virtual Polygon Extent();
};
