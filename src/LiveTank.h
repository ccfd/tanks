#pragma once
#include "Object.h"
#include "TankAvatar.h"
#include "Player.h"

const double cannonInterval = 2, gunInterval = 0.1;

class LiveTank : public Object {
	TankAvatar avatar;
	double x,y,rb,rh,rc,t;
	double cannonAmmunition, gunAmmunition, lastCannonShot, lastGunShot;
	void Shoot(App* app, double r, double hp, double pitch, double vb);
	void FillSights(Sights & sights, App* app, bool draw = false);
	Player* player;
	double HP;
public:
	LiveTank (Player *player_, double x_, double y_, double rb_, double rh_);
	~LiveTank ();
	virtual void Draw(App*,sf::RenderWindow* window);
	virtual void DrawExtents(App*,sf::RenderWindow* window);
	virtual void Tick(App* app);
	virtual Polygon Extent();
	virtual void Hit(double);
};
