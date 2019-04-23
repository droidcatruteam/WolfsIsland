#pragma once
#include "Cell.h"
#include <vector>

using namespace std;

class Board {
private:
	vector< vector<Cell> > field;
public:
	void show(int steps);
	Board();
	~Board();
};

