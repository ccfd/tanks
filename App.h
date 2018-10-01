#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Object.h"
#include <list>

class App {
public:
	typedef std::list<Object*> Objects;
private:
	sf::RenderWindow* window;
	sf::Sprite back;
	Objects objects;
	Objects bullets;
	sf::Sound hit;
public:
	App();
	void Draw();
	void DrawExtents();
	void Tick();
	int Run();
	void AddObject(Object*);
	void AddBullet(Object*);
	Objects GetCollision(Object *);
	void Hit(float pitch);
};
