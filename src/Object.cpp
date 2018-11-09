#include "Object.h"
#include "App.h"

Object::Object(tag_t tag_) {
	live = true;
	tag = tag_;
}

void Object::Hit(double hp) {

}

void Object::Dissapear() {
	live = false;
}

void Object::DrawExtents(App* app, sf::RenderWindow* window) {
		Polygon ext = this->Extent();
		std::vector<sf::Vertex> sfPoly;
		sf::Color color(0, 255, 0);
		if (Tag() == TAG_OBSTACLE) color = sf::Color(255, 0, 0);
		if (Tag() == TAG_ENEMY)    color = sf::Color(255, 255, 0);
		if (Tag() == TAG_DEADTANK)   color = sf::Color(255, 100, 100);
		if (Tag() == TAG_BULLET)   color = sf::Color(0, 255, 255);
		app->DrawPoly( ext, color );
}


Object::~Object() {

}