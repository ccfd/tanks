#pragma once
#include "Object.h"
#include "TankAvatar.h"
#include "Player.h"

const double cannonInterval = 2, gunInterval = 0.2;

class LiveTank : public Object {
	TankAvatar avatar;
	double x,y,rb,rh,rc,t;
	double cannonAmmunition, gunAmmunition, lastCannonShot, lastGunShot;
	void Shoot(App* app, double r, double pitch, double vb);
	Player* player;
public:
	LiveTank (Player *player_, double x_, double y_, double rb_, double rh_);
	~LiveTank ();
	virtual void Draw(sf::RenderWindow* window);
	virtual void Tick(App* app);
	virtual Polygon Extent();
};
