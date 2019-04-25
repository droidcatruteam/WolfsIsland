#pragma once
#include "Position.h"

class Rabbit {
private:
	Position pos;
	bool killed;
public:
	Position getpos();
	void setPos(Position p);
	bool isKilled();
	void setKilled(bool k);
	bool reproduct();
	Rabbit(int x, int y);
	~Rabbit();
};

