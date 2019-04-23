#include "pch.h"
#include "Position.h"

Position::Position() {}
Position::~Position() {}

Position Position::getpos() {
	Position p;
	p.x = x;
	p.y = y;
	return p;
}