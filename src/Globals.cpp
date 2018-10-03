#include "Globals.h"
#include <iostream>

void err(const std::string& msg) {
	std::cerr << msg << std::endl;
	exit(EXIT_FAILURE);
}

Resources::Resources() {
	if (!back.loadFromFile("media/back.jpg")) err("media/back.jpg not found");
	if (!head.loadFromFile("media/head.png")) err("media/head.png not found");
	if (!body.loadFromFile("media/body.png")) err("media/body.png not found");
	back.setSmooth(true);
	head.setSmooth(true);
	body.setSmooth(true);
	if (!shotbuffer.loadFromFile("media/lightmachinegun.ogg")) err("media/lightmachinegun.ogg not found");
	if (!hitbuffer.loadFromFile("media/hit1.ogg")) err("media/hit1.ogg not found");
}

Resources resources;


semiLineCut cutLine(const semiLine& line, const Point& p1, const Point& p2) {
	semiLineCut ret;
	// line.base + t*line.direction = w*p1 + (1-w)*p2
	// t*line.direction + w*(p2 - p1) = p2 - line.base
	double a11,a12,a21,a22,b1,b2;
	a11 = line.direction.x; a12 = p2.x - p1.x; b1 = p2.x - line.base.x;
	a21 = line.direction.y; a22 = p2.y - p1.y; b2 = p2.y - line.base.y;
	double det = a11*a22 - a21*a12;
	double t = (b1*a22 - b2*a12)/det;
	double w = (a11*b2 - a21*b1)/det;
	if ((t >= 0) && (0 <= w) && (w <= 1)) {
		ret.cut = line.base + line.direction * ((float) t);
		ret.count = 1;
		ret.distance = sqrt(line.direction.x*line.direction.x + line.direction.y*line.direction.y) * t;
	}
	return ret;
}

semiLineCut::semiLineCut(){
	count = 0;
}

void semiLineCut::add(const semiLineCut& line){
	if (line.count == 0) return;
	count = count + line.count;
	if (count == 0) {
		cut = line.cut;
		distance = line.distance;
	} else {
		if (distance > line.distance) {
			cut = line.cut;
			distance = line.distance;
		}                
	}
}


semiLineCut Polygon::cut(const semiLine& line) const {
	semiLineCut ret;
	if (this->size() > 1) {
		for (int i=0; i<this->size(); i++) {
			int j = i + 1;
			if (j >= this->size()) j=0;
			semiLineCut newcut = cutLine(line, (*this)[i], (*this)[j]);
			ret.add(newcut);
		}
	}
	return ret;
}

bool Polygon::inside(const Point& p) const {
	semiLine line(p, Point(1.0,0));
	semiLineCut mycut = this->cut(line);
	if (insideout) {
		return (mycut.count % 2) == 0;
	} else {
		return (mycut.count % 2) == 1;
	}
}

bool Polygon::intersect(const Polygon& ext) const {
	bool ret = false;
	for (Polygon::const_iterator p = ext.begin(); p != ext.end(); p++) {
		if (this->inside(*p)) ret = true;
	}
	for (Polygon::const_iterator p = this->begin(); p != this->end(); p++) {
		if (ext.inside(*p)) ret = true;
	}
	return ret;
}
