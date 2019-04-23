#pragma once
#include "Cell.h"
#include "Rabbit.h"
#include "Wolf.h"
#include <vector>

using namespace std;

class Board {
private:
	vector< vector<Cell> > field;
	vector<Wolf> wolfs;
	vector<Rabbit> rabbits;
public:
	void show(int steps);
	Board();
	~Board();
};

