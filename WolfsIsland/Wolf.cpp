#include "pch.h"
#include "Wolf.h"

Wolf::Wolf() {}
Wolf::~Wolf() {}

Position Wolf::getpos() {
	return pos;
}

sex Wolf::getSex() {
	return wolfSex;
}

float Wolf::getHp() {
	return hp;
}