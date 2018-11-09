#include "Globals.h"
#include "TankAvatar.h"
#include "Resources.h"

TankAvatar::TankAvatar () : 
		head(resources.head), 
		body(resources.body), 
		lifeStatus(sf::Vector2f(30, 3)),
		lifeFrame(sf::Vector2f(30, 3)) {
	head.setOrigin(72*0.5,72*0.75);
	body.setOrigin(72*0.5,72*0.5);
	head.scale(gscale,gscale);
	body.scale(gscale,gscale);
	if (!engine.openFromFile("media/sherman_e8.ogg")) err("media/sherman_e8.ogg not found"); // error
	engine.setLoop(true);
	shot.setBuffer(resources.shotbuffer);
	this->setPosition(600,600,0,0,0,1);
	engine.play();
	lifeStatus.setFillColor(resources.pencolor);
	lifeFrame.setOutlineThickness(1);
	lifeFrame.setOutlineColor(resources.pencolor);
	lifeFrame.setFillColor(sf::Color::Transparent);
	tankName.setFont(resources.bold);
	tankName.setCharacterSize(10);
        tankName.setColor(resources.pencolor);
        setName("unknown");
}

void TankAvatar::Draw(sf::RenderWindow* window) {
	window->draw(body);
	window->draw(head);
};

void TankAvatar::DrawInfo(sf::RenderWindow* window) {
	window->draw(lifeStatus);
	window->draw(lifeFrame);
	window->draw(tankName);
};

void TankAvatar::setName(const std::string& name_) {
	tankName.setString(name_);
	sf::FloatRect bounds = tankName.getLocalBounds();
	tankName.setOrigin(bounds.width/2,bounds.height + 50);
};

void TankAvatar::setPosition(double x, double y, double rb, double rh, double v, double life) {
	body.setPosition(x,y);
	head.setPosition(x,y);
	body.setRotation(rb*180/pi);
	head.setRotation(rh*180/pi);
	lifeFrame.setPosition(x-15,y-40);
	lifeStatus.setPosition(x-15,y-40);
	lifeStatus.setScale(life,1.0);
	tankName.setPosition(x,y);
	v = v/25;
	if (v<0) v=0;
	if (v>1) v=0;
	v = 0.8 + v*(2.0-0.8);
	engine.setPitch(v);
};

void TankAvatar::Shoot(float pitch) {
	shot.setPitch(pitch);
	shot.play();
};


