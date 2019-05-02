#pragma once
#include "Position.h"
#include "Utils.h"

class Wolf {
private:
	Position pos;
	sex wolfSex;
	int hp;
public:
	void setPos(Position p);
	void increaseHp();
	void decreaseHp();
	void setHp(int h);
	Position getpos();
	sex getSex();
	float getHp();
	Wolf(int x, int y, sex s);
	~Wolf();
};

