#include "Object.h"

Object::Object() {
	live = true;
	tag = TAG_UNKNOWN;
}

void Object::Hit(double hp) {

}

void Object::Dissapear() {
	live = false;
}

Object::~Object() {

}