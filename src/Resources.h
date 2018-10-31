#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <ostream>
#include <string>

struct Resources {
	sf::Texture back, head, body;
	sf::SoundBuffer shotbuffer, hitbuffer;
	Resources();
};

extern Resources resources;

