#include "Obstacle.h"
#include "App.h"

Obstacle::Obstacle (Polygon & poly_): Object(poly_.tag), poly(poly_) {

};

Obstacle::~Obstacle(){

};

void Obstacle::Draw(App*,sf::RenderWindow* window) {

};

void Obstacle::Tick(App* app) {

};

Polygon Obstacle::Extent() {
	return poly;
};

