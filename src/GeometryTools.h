#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Globals.h"

typedef sf::Vector2f Point;

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
	inline Polygon() { insideout = false; tag = TAG_UNKNOWN; }
	inline Polygon(const Polygon& poly_) : std::vector<Point>(poly_), insideout(poly_.insideout), tag(poly_.tag) { }
	semiLineCut cut(const semiLine&) const;
	bool inside(const Point&) const;
	bool intersect(const Polygon& ext) const;
};



