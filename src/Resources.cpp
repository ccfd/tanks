#include "Globals.h"
#include "Resources.h"

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
