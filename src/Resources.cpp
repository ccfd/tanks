#include "Globals.h"
#include "Resources.h"

Resources::Resources() {
	if (!back.loadFromFile("media/back.jpg")) err("media/back.jpg not found");
	if (!head.loadFromFile("media/head.png")) err("media/head.png not found");
	if (!hole.loadFromFile("media/hole.png")) err("media/hole.png not found");
	if (!body.loadFromFile("media/body.png")) err("media/body.png not found");
	back.setSmooth(true);
	head.setSmooth(true);
	body.setSmooth(true);
	if (!shotbuffer.loadFromFile("media/lightmachinegun.ogg")) err("media/lightmachinegun.ogg not found");
	if (!hitbuffer.loadFromFile("media/hit1.ogg")) err("media/hit1.ogg not found");
	if (!regular.loadFromFile("media/LiberationSans-Regular.ttf")) err("media/LiberationSans-Regular.ttf not found");
	if (!   bold.loadFromFile("media/LiberationSans-Bold.ttf"))    err("media/LiberationSans-Bold.ttf    not found");
	if (! italic.loadFromFile("media/LiberationSans-Italic.ttf"))  err("media/LiberationSans-Italic.ttf  not found");
}

Resources resources;
