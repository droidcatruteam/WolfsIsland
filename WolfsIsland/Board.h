#pragma once
#include "Cell.h"
#include "Rabbit.h"
#include "Wolf.h"
#include <vector>
#include "Utils.h"

using namespace std;

class Board {
private:
	vector< vector<Cell> > field;
	vector<Wolf> wolfs;
	vector<Rabbit> rabbits;
public:
	bool newWolf(Wolf &wolf);
	Position moveWolf(Wolf &wolf);
	void moveWolfs();
	bool newRabbit(Rabbit &rabbit);
	Position moveRabbit(Rabbit &rabbit);
	void moveRabbits();
	void reproductRabbits();
	void show(int steps);
	Board();
	~Board();
};

