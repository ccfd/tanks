#pragma once
#include "Object.h"
#include "TankControl.h"
#include "TankAvatar.h"

const double cannonInterval = 2, gunInterval = 0.1;

class LiveTank : public Object {
	TankAvatar avatar;
	double x,y,rb,rh,rc,t;
	double cannonAmmunition, gunAmmunition, lastCannonShot, lastGunShot;
	void Shoot(App* app, double r, double hp, double pitch, double vb);
	void FillSights(Sights & sights, App* app, bool draw = false);
	double HP;
	bool dead;
	void Die();
	TankControl control;
public:
	LiveTank (double x_, double y_, double rb_, double rh_, const std::string & name_);
	~LiveTank ();
	virtual void Draw(App*,sf::RenderWindow* window);
	virtual void DrawExtents(App*,sf::RenderWindow* window);
	virtual void Tick(App* app);
	virtual Polygon Extent();
	virtual void Hit(double);
	TankControl& getControl(App* app);
	inline double getHP() { return HP; };
};
