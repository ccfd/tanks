#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <ostream>

const double gscale = 630.0/1080.0;
const double pi = atan(1.0)*4;
const double dt = 1.0/24.0;

void err(char * msg);

struct Resources {
    sf::Texture back, head, body;
	sf::SoundBuffer shotbuffer;
	Resources();
};

extern Resources resources;

struct Point {
	double x[2];
	inline Point(double x_, double y_) { x[0] = x_; x[1] = y_; };
};

struct Polygon : public std::vector<Point> {

};
