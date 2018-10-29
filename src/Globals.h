#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <ostream>
#include <string>

//const double gscale = 630.0/1080.0;
const double gscale = 720.0/1080.0;
const double pi = atan(1.0)*4;
const double dt = 1.0/24.0;

void err(const std::string& msg);

struct Resources {
	sf::Texture back, head, body;
	sf::SoundBuffer shotbuffer, hitbuffer;
	Resources();
};

extern Resources resources;

typedef sf::Vector2f Point;

typedef unsigned int tag_t;
#define TAG_UNKNOWN 1
#define TAG_PLAYER 2
#define TAG_MAXPLAYER 30
#define TAG_OBSTACLE 30
#define TAG_FOOD 31

struct semiLine {
	Point base, direction;
	inline semiLine(Point base_, Point direction_): base(base_), direction(direction_) {};
};

struct semiLineCut {
	Point cut;
	double distance;
	int count;
	tag_t tag;
	semiLineCut();
	void add(const semiLineCut&);
};

struct Polygon : public std::vector<Point> {
	bool insideout;
	tag_t tag;
	inline Polygon() { insideout = false; tag = 0; }
	inline Polygon(const Polygon& poly_) : std::vector<Point>(poly_), insideout(poly_.insideout), tag(poly_.tag) { }
	semiLineCut cut(const semiLine&) const;
	bool inside(const Point&) const;
	bool intersect(const Polygon& ext) const;
};



