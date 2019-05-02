#include "pch.h"
#include "Wolf.h"

Wolf::Wolf(int x, int y, sex s) {
	pos.x = x;
	pos.y = y;
	wolfSex = s;
	hp = 15;
}
Wolf::~Wolf() {}

void Wolf::increaseHp() {
	if (hp <= 20) {
		hp += 10;
	}
	else {
		hp = 30;
	}
}

void Wolf::decreaseHp() {
	hp = hp - 1;
}

void Wolf::setHp(int h) {
	hp = h;
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