#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <ostream>
#include <string>

struct Resources {
	sf::Texture back, head, body, hole;
	sf::SoundBuffer shotbuffer, hitbuffer;
	sf::Font regular, bold, italic;
	sf::Color pencolor;
	Resources();
};

extern Resources resources;

