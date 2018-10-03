#pragma once

#include "Object.h"

class Bullet : public Object {
	double  x, y;
	double vx,vy;
	double r;
	double hp;
	sf::CircleShape circle;
public:
	Bullet (double x_, double y_, double vx_, double vy_, double r_, double hp_);
	virtual ~Bullet();
	virtual void Draw(sf::RenderWindow* window);
	virtual void Tick(App*);
	virtual Polygon Extent();
};
