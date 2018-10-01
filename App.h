#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Object.h"
#include <list>

class App {
	sf::RenderWindow* window;
	sf::Sprite back;
	typedef std::list<Object*> Tanks;
	Tanks tanks;
public:
	App();
	void Draw();
	void DrawExtents();
	void Tick();
	int Run();
	void AddObject(Object*);
	std::vector<Object*> GetCollision(Object *);
};
