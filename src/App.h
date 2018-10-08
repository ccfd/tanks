#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Object.h"
#include <list>

class App {
public:
	typedef std::list<Object*> Objects;
	typedef std::vector<std::string> Strings;
private:
	sf::RenderWindow* window;
	sf::Sprite back;
	Objects objects;
	Objects bullets;
	sf::Sound hit;
	Strings playerNames;
public:
	App(const Strings&);
	void Draw();
	void DrawExtents();
	void Tick();
	int Run();
	void AddObject(Object*);
	void AddBullet(Object*);
	Objects GetCollision(Object *);
	void Hit(float pitch);
	semiLineCut GetCut(Object * obj, const semiLine &line);
};
