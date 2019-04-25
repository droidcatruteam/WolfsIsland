#include "pch.h"
#include "Cell.h"


Cell::Cell(int x, int y) {
	pos.x = x;
	pos.y = y;
	stat = empty;
}

Cell::~Cell() {}

void Cell::setEmpty() {
	stat = empty;
}

void Cell::setWolfM() {
	stat = wolfm;
}

void Cell::setWolfF() {
	stat = wolff;
}

void Cell::setRabbit() {
	stat = rabbit;
}

char Cell::getStatus() {
	switch (stat) {
	case empty:
		return '+';
		break;
	case wolfm:
		return 'M';
		break;
	case wolff:
		return 'F';
		break;
	case rabbit:
		return 'R';
		break;
	default:
		return '+';
		break;
	}
}
