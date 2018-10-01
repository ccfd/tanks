#include "Globals.h"
#include "TankAvatar.h"

TankAvatar::TankAvatar ():head(resources.head), body(resources.body) {
		head.setOrigin(72*0.5,72*0.75);
		body.setOrigin(72*0.5,72*0.5);
		head.scale(gscale,gscale);
	    body.scale(gscale,gscale);
//		head.setColor(sf::Color(128, 255, 128));
//		body.setColor(sf::Color(128, 255, 128));
		if (!engine.openFromFile("sherman_e8.ogg")) err("sherman_e8.ogg not found"); // error
		engine.setLoop(true);
		shot.setBuffer(resources.shotbuffer);
		this->setPosition(600,600,0,0,0);
		if (!mute) engine.play();
	}
	void TankAvatar::Draw(sf::RenderWindow* window) {
        window->draw(body);
        window->draw(head);
	};
	void TankAvatar::setPosition(double x, double y, double rb, double rh, double v) {
		body.setPosition(x,y);
		head.setPosition(x,y);
		body.setRotation(rb*180/pi);
		head.setRotation(rh*180/pi);
		v = v/25;
		if (v<0) v=0;
		if (v>1) v=0;
		v = 0.8 + v*(2.0-0.8);
		engine.setPitch(v);
	};
	void TankAvatar::Shoot(float pitch) {
		shot.setPitch(pitch);
		if (!mute) shot.play();
	};


