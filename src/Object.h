#pragma once
#include "Globals.h"
#include "GeometryTools.h"

class App;

class Object {
	bool live;
	tag_t tag;
public:
	Object(tag_t tag_ = TAG_UNKNOWN);
	virtual ~Object();
	virtual void Draw(App*, sf::RenderWindow* window) = 0;
	virtual void DrawExtents(App*, sf::RenderWindow* window);
	virtual void Tick(App*) = 0;
	virtual Polygon Extent() = 0;
	virtual void Hit(double);
	virtual void Dissapear();
	inline tag_t& Tag() { return tag; };
	inline bool IsAlive() { return live; }
};
