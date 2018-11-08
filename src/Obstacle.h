#pragma once

#include "Object.h"

class Obstacle : public Object {
	Polygon poly;
	sf::Color color;
public:
	Obstacle (Polygon & poly_, sf::Color color_ = sf::Color(255,255,255,255));
	virtual ~Obstacle();
	virtual void Draw(App*,sf::RenderWindow* window);
	virtual void Tick(App*);
	virtual Polygon Extent();
};
