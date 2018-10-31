#pragma once
#include <math.h>
#include <string>

const double gscale = 720.0/1080.0;
const double pi = atan(1.0)*4;
const double dt = 1.0/24.0;

void err(const std::string& msg);

typedef unsigned int tag_t;
#define TAG_UNKNOWN 1
#define TAG_PLAYER 2
#define TAG_MAXPLAYER 30
#define TAG_OBSTACLE 30
#define TAG_FOOD 31

