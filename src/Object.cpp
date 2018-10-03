#include "Object.h"

Object::Object() {
	live = true;
}

void Object::Hit(double hp) {

}

void Object::Dissapear() {
	live = false;
}

Object::~Object() {

}