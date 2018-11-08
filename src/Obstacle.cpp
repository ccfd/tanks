#include "Obstacle.h"
#include "App.h"

Obstacle::Obstacle (Polygon & poly_, sf::Color color_): Object(poly_.tag), poly(poly_), color(color_) {

};

Obstacle::~Obstacle(){

};

void Obstacle::Draw(App* app,sf::RenderWindow* window) {
	app->DrawPoly(poly,color);
};

void Obstacle::Tick(App* app) {

};

Polygon Obstacle::Extent() {
	return poly;
};

