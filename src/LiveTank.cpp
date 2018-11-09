#include "LiveTank.h"
#include "App.h"
#include "Bullet.h"
#include <stdlib.h>
#include <stdio.h>
#include "TankControl.h"


LiveTank::LiveTank (double x_, double y_, double rb_, double rh_, const std::string & name_) : Object(TAG_UNKNOWN), x(x_), y(y_), rb(rb_), rh(rh_), t(0) {
	rc = 0;
	gunAmmunition = 1000;
	cannonAmmunition = 10;
	lastCannonShot = prepTime;
	lastGunShot = prepTime;
	HP = 100;
	avatar.setName(name_);
	dead = false;
}

LiveTank::~LiveTank() {};

void LiveTank::Hit(double hp) {
	HP -= hp;
	if (HP <= 0) {
		HP = 0;
		Die();
	}
}

void LiveTank::Die() {
	dead = true;
	Tag() = TAG_DEADTANK;
};

void LiveTank::Draw(App* app,sf::RenderWindow* window) {
	avatar.Draw(window);
	if (! dead) avatar.DrawInfo(window);
};

void LiveTank::FillSights(Sights & sights, App* app, bool draw) {
	for (Sights::iterator it = sights.begin(); it != sights.end(); it++) {
		double r = it->angle + rh;
		semiLine line(Point(x,y), Point(sin(r),-cos(r)));
		semiLineCut cut = app->GetCut(this,line,draw);
		it->distance = cut.distance;
		it->tag = cut.tag;
	}
};

void LiveTank::DrawExtents(App* app,sf::RenderWindow* window) {
	Object::DrawExtents(app,window);
	TankControl control;
	FillSights(control.sights,app,true);
	if (! dead) avatar.DrawInfo(window);
};

TankControl& LiveTank::getControl(App* app) {
	control.Init();
	control.azimuth = rh;
	control.cannonAmmunition = cannonAmmunition;
	control.gunAmmunition = gunAmmunition;
	control.cannonAngle = rc;
	bool canShootCannon = (cannonAmmunition > 0) && (t - lastCannonShot > cannonInterval);
	bool canShootGun = (gunAmmunition > 0) && (t - lastGunShot > gunInterval);
	control.canShootCannon = canShootCannon;
	control.canShootGun = canShootGun;
	control.headAngle = rh - rb;
	
	FillSights(control.sights,app);
	return control;
};

void LiveTank::Tick(App* app) {
	t += dt;
	if (dead) return;
	bool canShootCannon = (cannonAmmunition > 0) && (t - lastCannonShot > cannonInterval);
	bool canShootGun = (gunAmmunition > 0) && (t - lastGunShot > gunInterval);
	double v1=0, v2=0, omh = 1;
	v1 = control.left;
	if (v1 >  25) v1 =  25;
	if (v1 < -25) v1 = -25;
	v2 = control.right;
	if (v2 >  25) v2 =  25;
	if (v2 < -25) v2 = -25;
	omh = control.turn;
	if (omh >  1) omh =  1;
	if (omh < -1) omh = -1;

	double v = (v1+v2)/2;
	double om = (-v1+v2)/24;

	{
		double ox=x, oy=y, orb=rb, orh=rh;
		x +=  sin(rb)*v*dt;
		y += -cos(rb)*v*dt;
		rb += om*dt;
		rh += om*dt;
		App::Objects col = app->GetCollision(this);
		if (col.size() > 0) {
			x = ox;
			y = oy;
			rb = orb;
			rh = orh;
		}
		rh += omh*dt;
	}

	v = fabs(v1);
	if (v < fabs(v2)) v = fabs(v2);
	avatar.setPosition(x,y,rb,rh,v,HP/100.0);

	if (canShootCannon && control.wannaShootCannon) {
		Shoot(app,
			2,   // bullet radius
			50,  // bullet HP
			0.5, // sound pitch
			40   // speed
		);
		cannonAmmunition--;
		lastCannonShot = t;
	} else if (canShootGun && control.wannaShootGun) {
		Shoot(app, 
			1.3, // bullet radius
			1,   // bullet HP
			1.0, // sound pitch
			200  // speed
		);
		gunAmmunition--;
		lastGunShot = t;
	}
};

void LiveTank::Shoot(App* app, double r, double hp, double pitch, double vb) {
	double l = 30;
	avatar.Shoot(pitch);
	app->AddBullet(new Bullet(x+l*sin(rh),y-l*cos(rh),vb*sin(rh),-vb*cos(rh), r, hp));
};

Polygon LiveTank::Extent() {
	Polygon poly;
	double w=20,h=15;
	poly.push_back(Point(x+w*sin(rb)+h*cos(rb),y-w*cos(rb)+h*sin(rb)));
	poly.push_back(Point(x+w*sin(rb)-h*cos(rb),y-w*cos(rb)-h*sin(rb)));
	poly.push_back(Point(x-w*sin(rb)-h*cos(rb),y+w*cos(rb)-h*sin(rb)));
	poly.push_back(Point(x-w*sin(rb)+h*cos(rb),y+w*cos(rb)+h*sin(rb)));
	poly.tag = Tag();
	return poly;
};

