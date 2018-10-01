#include "Obstacle.h"
#include "App.h"

Obstacle::Obstacle (Polygon & poly_): poly(poly_) {

};

Obstacle::~Obstacle(){

};

void Obstacle::Draw(sf::RenderWindow* window) {

};

void Obstacle::Tick(App* app) {

};

Polygon Obstacle::Extent() {
	return poly;
};

