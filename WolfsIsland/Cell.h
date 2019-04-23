#pragma once
#include "Position.h"

enum status {empty, wolfm, wolff, sheep};

class Cell {
private:
	Position pos;
	status stat;
public:
	char getStatus();
	Cell(int x, int y);
	~Cell();
};

