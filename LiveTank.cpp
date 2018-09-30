#include "LiveTank.h"
#include "App.h"
#include "Bullet.h"
#include "stdlib.h"


LiveTank::LiveTank (double x_, double y_, double rb_, double rh_) : x(x_), y(y_), rb(rb_), rh(rh_), t(0) {
		i=0;
		ran = 1.0*rand()/RAND_MAX+1;
	}

LiveTank::~LiveTank() {};

	void LiveTank::Draw(sf::RenderWindow* window) {
		avatar.Draw(window);
	};
	void LiveTank::Tick(App* app) {
		t += dt;
		
		double v1=0, v2=0, omh = 1;
		v1 = sin(t*ran)*25;
//		v2 = sin(t/10)*25;
		v2 = v1;
		double v = (v1+v2)/2;
		double om = (v1-v2)/24;
		x +=  sin(rb)*v*dt;
		y += -cos(rb)*v*dt;
		rb += om*dt;
		rh += (om+omh)*dt;
		v = fabs(v1);
		if (v < fabs(v2)) v = fabs(v2);
		avatar.setPosition(x,y,rb,rh,v);
		double l = 25, vb = 200;
		i++;
		if (i % 4 == 0) {
			avatar.Shoot(1.0);
			app->AddObject(new Bullet(x+l*sin(rh),y-l*cos(rh),vb*sin(rh),-vb*cos(rh),1));
		}
	};
	Polygon LiveTank::Extent() {
		Polygon poly;
		double w=18,h=15;
		poly.push_back(Point(x+w*sin(rb)+h*cos(rb),y-w*cos(rb)+h*sin(rb)));
		poly.push_back(Point(x+w*sin(rb)-h*cos(rb),y-w*cos(rb)-h*sin(rb)));
		poly.push_back(Point(x-w*sin(rb)-h*cos(rb),y+w*cos(rb)-h*sin(rb)));
		poly.push_back(Point(x-w*sin(rb)+h*cos(rb),y+w*cos(rb)+h*sin(rb)));
		return poly;
	};

