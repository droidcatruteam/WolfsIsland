#pragma once
#include "Board.h"

class Game {
private:
	Board gameboard;
	int stepsCount;
public:
	void makestep();
	void showboard();
	Game();
	~Game();
};

