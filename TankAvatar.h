#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class TankAvatar {
	sf::Sprite head, body;
	sf::Music engine;
	sf::Sound shot;
public:
	TankAvatar ();
	void Draw(sf::RenderWindow* window);
	void setPosition(double x, double y, double rb, double rh, double v);
	void Shoot(float pitch);
};

