#pragma once
#include "Globals.h"

class App;

class Object {
public:
	virtual ~Object();
	virtual void Draw(sf::RenderWindow* window) = NULL;
	virtual void Tick(App*) = NULL;
	virtual Polygon Extent() = NULL;
};
