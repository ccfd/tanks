#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Object.h"
#include "GeometryTools.h"
#include <list>

class App {
public:
	typedef std::list<Object*> Objects;
	typedef std::vector<std::string> Strings;
private:
	sf::RenderWindow* window;
	sf::Sprite back;
	sf::Text clockText;
	Objects objects;
	Objects bullets;
	sf::Sound hit;
	Strings playerNames;
	bool fullScreen;
	bool mute;
	bool graphics, extents;
	double timeLimit;
	double fps;
	double Time;
public:
	App(const Strings&);
	void Draw();
	void DrawExtents();
	void DrawPoly(const Polygon&, const sf::Color&);
	void Tick();
	int Run();
	void AddObject(Object*);
	void AddBullet(Object*);
	Objects GetCollision(Object *);
	void Hit(float pitch);
	semiLineCut GetCut(Object * obj, const semiLine &line, bool draw=false);
};
