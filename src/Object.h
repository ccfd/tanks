#pragma once
#include "Globals.h"

class App;

class Object {
	bool live;
	tag_t tag;
public:
	Object();
	virtual ~Object();
	virtual void Draw(App*, sf::RenderWindow* window) = 0;
	virtual void DrawExtents(App*, sf::RenderWindow* window);
	virtual void Tick(App*) = 0;
	virtual Polygon Extent() = 0;
	virtual void Hit(double);
	virtual void Dissapear();
	inline const tag_t& Tag() { return tag; };
	inline bool IsAlive() { return live; }
};
