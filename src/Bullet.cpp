#include "Bullet.h"
#include "App.h"

Bullet::Bullet (double x_, double y_, double vx_, double vy_, double r_, double hp_): x(x_), y(y_), vx(vx_), vy(vy_), r(r_), circle(r), hp(hp_) {
	circle.setFillColor(sf::Color(0, 0, 0));
	circle.setOrigin(r,r);
};

Bullet::~Bullet(){

};

void Bullet::Draw(sf::RenderWindow* window) {
	window->draw(circle);
};
void Bullet::Tick(App* app) {
	x = x + vx*dt;
	y = y + vy*dt;
	circle.setPosition(x,y);
	App::Objects col = app->GetCollision(this);
	for (App::Objects::iterator t = col.begin(); t != col.end(); t++) {
		(*t)->Hit(hp);
		app->Hit(1.0);
		Dissapear();
	}
};
Polygon Bullet::Extent() {
	Polygon poly;
	poly.push_back(Point(x+r,y+r));
	poly.push_back(Point(x+r,y-r));
	poly.push_back(Point(x-r,y-r));
	poly.push_back(Point(x-r,y+r));
	return poly;
};

