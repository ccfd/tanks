#pragma once
#include <math.h>
#include <string>

const double gscale = 720.0/1080.0;
const double pi = atan(1.0)*4;
const double dt = 1.0/24.0;
const double prepTime = 3.0;

void err(const std::string& msg);

typedef unsigned int tag_t;
#define TAG_UNKNOWN 1
#define TAG_ENEMY 2
#define TAG_ALLY 3
#define TAG_DEADTANK 4
#define TAG_OBSTACLE 5
#define TAG_FOOD 6
#define TAG_BULLET 7
