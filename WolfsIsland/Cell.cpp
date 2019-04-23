#include "pch.h"
#include "Cell.h"


Cell::Cell(int x, int y) {
	pos.x = x;
	pos.y = y;
	stat = empty;
}

Cell::~Cell() {}

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
	case sheep:
		return 'S';
		break;
	default:
		return '+';
		break;
	}
}
