#pragma once
#include "Globals.h"

class App;

class Object {
	bool live;
public:
	Object();
	virtual ~Object();
	virtual void Draw(App*, sf::RenderWindow* window) = 0;
	virtual void Tick(App*) = 0;
	virtual Polygon Extent() = 0;
	virtual void Hit(double);
	virtual void Dissapear();
	inline bool IsAlive() { return live; }
};
