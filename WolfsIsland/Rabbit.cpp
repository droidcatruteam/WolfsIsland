#include "pch.h"
#include "Rabbit.h"
#include <random>

Rabbit::Rabbit(int x, int y) {
	killed = false;
	pos.x = x;
	pos.y = y;
}
Rabbit::~Rabbit() {}

Position Rabbit::getpos() {
	return pos;
}

void Rabbit::setPos(Position p) {
	pos = p;
}

void Rabbit::setKilled(bool k) {
	killed = k;
}

bool Rabbit::isKilled() {
	return killed;
}

bool Rabbit::reproduct() {
	int i = rand() % 5;
	if (i == 0) {
		return true;
	}
	return false;
}