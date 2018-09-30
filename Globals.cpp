#include "Globals.h"
#include <iostream>

void err(char * msg) {
	std::cerr << msg << std::endl;
	exit(EXIT_FAILURE);
}

Resources::Resources() {
	    if (!back.loadFromFile("back.jpg")) err("back.jpg not found");
		if (!head.loadFromFile("head.png")) err("head.png not found");
		if (!body.loadFromFile("body.png")) err("body.png not found");
		back.setSmooth(true);
		head.setSmooth(true);
		body.setSmooth(true);
		if (!shotbuffer.loadFromFile("lightmachinegun.ogg")) err("lightmachinegun.ogg not found");
	}

Resources resources;
