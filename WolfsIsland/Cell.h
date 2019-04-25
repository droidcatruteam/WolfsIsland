#pragma once
#include "Position.h"
#include "Utils.h"

class Cell {
private:
	Position pos;
	status stat;
public:
	char getStatus();
	void setWolfM();
	void setWolfF();
	void setRabbit();
	void setEmpty();
	Cell(int x, int y);
	~Cell();
};

