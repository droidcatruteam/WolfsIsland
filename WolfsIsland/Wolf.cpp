#include "pch.h"
#include "Wolf.h"

Wolf::Wolf(int x, int y, sex s) {
	pos.x = x;
	pos.y = y;
	wolfSex = s;
	hp = 10;
}
Wolf::~Wolf() {}

void Wolf::increaseHp() {
	hp += 10;
}

void Wolf::decreaseHp() {
	hp = hp - 1;
}

void Wolf::setPos(Position p) {
	pos = p;
}

Position Wolf::getpos() {
	return pos;
}

sex Wolf::getSex() {
	return wolfSex;
}

float Wolf::getHp() {
	return hp;
}