#pragma once
#include "Position.h"

typedef enum sex{m, f};

class Wolf {
private:
	Position pos;
	sex wolfSex;
	float hp;
public:
	Position getpos();
	sex getSex();
	float getHp();
	Wolf();
	~Wolf();
};

