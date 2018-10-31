#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class TankAvatar {
	sf::Sprite head, body;
	sf::Music engine;
	sf::Sound shot;
	sf::RectangleShape lifeStatus;
	sf::RectangleShape lifeFrame;
	sf::Text tankName;
public:
	TankAvatar ();
	void Draw(sf::RenderWindow* window);
	void DrawInfo(sf::RenderWindow* window);
	void setPosition(double x, double y, double rb, double rh, double v, double life);
	void setName(const std::string& name_);
	void Shoot(float pitch);
};

