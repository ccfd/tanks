#include "Bullet.h"

Bullet::Bullet (double x_, double y_, double vx_, double vy_, double r_): x(x_), y(y_), vx(vx_), vy(vy_), r(r_), circle(r) {
		circle.setFillColor(sf::Color(0, 0, 0));
		circle.setOrigin(r,r);
	};

	Bullet::~Bullet(){};

	void Bullet::Draw(sf::RenderWindow* window) {
		window->draw(circle);
	};
	void Bullet::Tick(App*) {
		x = x + vx*dt;
		y = y + vy*dt;
		circle.setPosition(x,y);
	};
	Polygon Bullet::Extent() {
		Polygon poly;
		poly.push_back(Point(x+r,y+r));
		poly.push_back(Point(x+r,y-r));
		poly.push_back(Point(x-r,y-r));
		poly.push_back(Point(x-r,y+r));
		return poly;
	};

