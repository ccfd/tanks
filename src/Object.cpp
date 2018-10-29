#include "Object.h"
#include "App.h"

Object::Object() {
	live = true;
	tag = TAG_UNKNOWN;
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
		int count = app->GetCollision(this).size();
		if (count == 1) {
			color = sf::Color(255, 0, 0);
		}
		if (count == 2) {
			color = sf::Color(255, 255, 0);
		}
		if (count == 3) {
			color = sf::Color(0, 255, 255);
		}
		if (count == 4) {
			color = sf::Color(0, 0, 255);
		}
		for (Polygon::iterator p = ext.begin(); p != ext.end(); p++) {
			sfPoly.push_back(sf::Vertex(*p, color));
		}
		{
			Polygon::iterator p = ext.begin();
			sfPoly.push_back(sf::Vertex(*p, color));
		}
		window->draw(&sfPoly[0], sfPoly.size(), sf::LinesStrip);

}


Object::~Object() {

}