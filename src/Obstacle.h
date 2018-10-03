#pragma once

#include "Object.h"

class Obstacle : public Object {
	Polygon poly;
public:
	Obstacle (Polygon & poly_);
	virtual ~Obstacle();
	virtual void Draw(App*,sf::RenderWindow* window);
	virtual void Tick(App*);
	virtual Polygon Extent();
};
