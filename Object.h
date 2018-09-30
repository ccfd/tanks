#pragma once
#include "Globals.h"

class App;

class Object {
public:
	virtual ~Object();
	virtual void Draw(sf::RenderWindow* window) = 0;
	virtual void Tick(App*) = 0;
	virtual Polygon Extent() = 0;
};
