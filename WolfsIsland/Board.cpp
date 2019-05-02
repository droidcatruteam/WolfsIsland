#include "pch.h"
#include "Board.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

Board::Board() {
	for (int y = 0; y < FIELDSIZE; y++) {
		vector<Cell> column;
		for (int x = 0; x < FIELDSIZE; x++) {
			Cell cell(x, y);
			column.push_back(cell);
		}
		field.push_back(column);
	}
	for (int i = 0; i < 5; i++) {
		int x = rand() % FIELDSIZE;
		int y = rand() % FIELDSIZE;
		sex s = (sex)(rand() % 2);
		Wolf wolf(x, y, s);
		if (!newWolf(wolf)) {
			i--;
		}
	}
	for (int i = 0; i < 10; i++) {
		int x = rand() % FIELDSIZE;
		int y = rand() % FIELDSIZE;
		Rabbit rabbit(x, y);
		if (!newRabbit(rabbit)) {
			i--;
		}
	}
}

Board::~Board() {}

bool Board::newWolf(Wolf &wolf) {
	int x = wolf.getpos().x;
	int y = wolf.getpos().y;
	if (x >= 0 && y >= 0 && x <= FIELDSIZE && y <= FIELDSIZE && field.at(x).at(y).getStatus() == '+') {
		if (wolf.getSex() == m) {
			field.at(x).at(y).setWolfM();
		}
		else {
			field.at(x).at(y).setWolfF();
		}
		wolfs.push_back(wolf);
		return true;
	}
	return false;
}

bool Board::newRabbit(Rabbit &rabbit) {
	int x = rabbit.getpos().x;
	int y = rabbit.getpos().y;
	if (x >= 0 && y >= 0 && x <= FIELDSIZE && y <= FIELDSIZE && field.at(x).at(y).getStatus() == '+') {
		field.at(x).at(y).setRabbit();
		rabbits.push_back(rabbit);
		return true;
	}
	return false;
}

Position Board::moveRabbit(Rabbit &rabbit) {
	Position pos = rabbit.getpos();
	int x = rabbit.getpos().x;
	int y = rabbit.getpos().y;
	vector<Position> query;
	if (x > 0) {
		pos.x = x - 1;
		pos.y = y;
		query.push_back(pos);
	}
	if (x < FIELDSIZE - 1) {
		pos.x = x + 1;
		pos.y = y;
		query.push_back(pos);
	}
	if (y > 0) {
		pos.x = x;
		pos.y = y - 1;
		query.push_back(pos);
	}
	if (y < FIELDSIZE - 1) {
		pos.x = x;
		pos.y = y + 1;
		query.push_back(pos);
	}
	if (y > 0 && x > 0) {
		pos.x = x - 1;
		pos.y = y - 1;
		query.push_back(pos);
	}
	if (y > 0 && x < FIELDSIZE - 1) {
		pos.x = x + 1;
		pos.y = y - 1;
		query.push_back(pos);
	}
	if (y < FIELDSIZE - 1 && x > 0) {
		pos.x = x - 1;
		pos.y = y + 1;
		query.push_back(pos);
	}
	if (y < FIELDSIZE - 1 && x < FIELDSIZE - 1) {
		pos.x = x + 1;
		pos.y = y + 1;
		query.push_back(pos);
	}
	for (int i = query.size() - 1; i >= 0; i--) {
		if (field.at(query.at(i).getpos().x).at(query.at(i).getpos().y).getStatus() == 'R') {
			query.erase(query.begin() + i);
		}
	}
	if (query.size() > 0) {
		int p = rand() % query.size();
		field.at(rabbit.getpos().x).at(rabbit.getpos().y).setEmpty();
		if (field.at(x).at(y).getStatus() == '+')
			field.at(query.at(p).getpos().x).at(query.at(p).getpos().y).setRabbit();

		return query.at(p).getpos();
	}
	else {
		return rabbit.getpos();
	}
}

void Board::moveRabbits() {
	for (int i = 0; i < rabbits.size(); i++) {
		if (rand() % 9 != 0) {
			rabbits.at(i).setPos(moveRabbit(rabbits.at(i)));
		}
		if (rand() % 5 == 0) {
			Rabbit r = rabbits.at(i);
			Position p = moveRabbit(r);
			if (p.x != rabbits.at(i).getpos().x || p.y != rabbits.at(i).getpos().y) {
				r.setPos(p);
				rabbits.push_back(r);
			}
		}
	}
}

void Board::reproductRabbits() {
	int c = rabbits.size();
	for (int i = 0; i < c; i++) {
		if (rand() % 5 == 0) {
			Rabbit r = rabbits.at(i);
			Position p = moveRabbit(r);
			if (p.x != rabbits.at(i).getpos().x || p.y != rabbits.at(i).getpos().y) {
				r.setPos(p);
				rabbits.push_back(r);
			}
		}
	}
}

Position Board::moveWolf(Wolf &wolf) {
	Position pos = wolf.getpos();
	int x = wolf.getpos().x;
	int y = wolf.getpos().y;
	vector<Position> query;
	if (x > 0) {
		pos.x = x - 1;
		pos.y = y;
		query.push_back(pos);
	}
	if (x < FIELDSIZE-1) {
		pos.x = x + 1;
		pos.y = y;
		query.push_back(pos);
	}
	if (y > 0) {
		pos.x = x;
		pos.y = y - 1;
		query.push_back(pos);
	}
	if (y < FIELDSIZE-1) {
		pos.x = x;
		pos.y = y + 1;
		query.push_back(pos);
	}
	if (y > 0 && x > 0) {
		pos.x = x - 1;
		pos.y = y - 1;
		query.push_back(pos);
	}
	if (y > 0 && x < FIELDSIZE-1) {
		pos.x = x + 1;
		pos.y = y - 1;
		query.push_back(pos);
	}
	if (y < FIELDSIZE-1 && x > 0) {
		pos.x = x - 1;
		pos.y = y + 1;
		query.push_back(pos);
	}
	if (y < FIELDSIZE-1 && x < FIELDSIZE-1) {
		pos.x = x + 1;
		pos.y = y + 1;
		query.push_back(pos);
	}

	int p = rand() % query.size();
	for (int i = 0; i < query.size(); i++) {
		if (field.at(query.at(i).getpos().x).at(query.at(i).getpos().y).getStatus() == 'R' && wolf.getHp() <= 15) {
			p = i;
			break;
		}
		else if (field.at(query.at(i).getpos().x).at(query.at(i).getpos().y).getStatus() == 'M' && wolf.getSex() == f && wolf.getHp() > 15) {
			return wolf.getpos();
		}
		else if (field.at(query.at(i).getpos().x).at(query.at(i).getpos().y).getStatus() == 'F' && wolf.getSex() == m && wolf.getHp() > 15) {
			p = i;
			for (int g = 0; g < wolfs.size(); g++) {
				if (wolfs.at(g).getpos().x == query.at(i).getpos().x && wolfs.at(g).getpos().y == query.at(i).getpos().y) {
					wolfs.at(g).setHp(15);
					wolf.setHp(15);
				}
			}
			Wolf w(query.at(i).getpos().x, query.at(i).getpos().y, (sex)(rand() % 2));
			newWolf(w);
			moveWolf(w);
			break;
		}
	}
	field.at(wolf.getpos().x).at(wolf.getpos().y).setEmpty();
	if(wolf.getSex() == m)
		field.at(query.at(p).getpos().x).at(query.at(p).getpos().y).setWolfM();
	else
		field.at(query.at(p).getpos().x).at(query.at(p).getpos().y).setWolfF();

	return query.at(p).getpos();
}

void Board::moveWolfs() {
	for (int i = wolfs.size() - 1; i >= 0; i--) {
		bool rabbitKilled = false;
		wolfs.at(i).setPos(moveWolf(wolfs.at(i)));
		for (int g = 0; g < rabbits.size(); g++) {
			if (rabbits.at(g).getpos().x == wolfs.at(i).getpos().x && rabbits.at(g).getpos().y == wolfs.at(i).getpos().y) {
				wolfs.at(i).increaseHp();
				rabbits.erase(rabbits.begin() + g);
				rabbitKilled = true;
				break;
			}
		}
		if (!rabbitKilled) {
			wolfs.at(i).decreaseHp();
			if (wolfs.at(i).getHp() == 0) {
				field.at(wolfs.at(i).getpos().x).at(wolfs.at(i).getpos().y).setEmpty();
				wolfs.erase(wolfs.begin() + i);
			}
		}
	}
}

void setcolor(unsigned int color, unsigned int background_color) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color | background_color * 16 + color);
}

void Board::show(int steps) {
	//system("CLS");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);

	COORD coord{ 0,0 }; //sets cursor position to (0;0)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	
	for (int y = 0; y < FIELDSIZE; y++) {
		for (int x = 0; x < FIELDSIZE; x++) {
			switch (field.at(x).at(y).getStatus()) {
			case 'F':
				setcolor(LIGHTRED, BLACK);
				break;
			case 'M':
				setcolor(RED, BLACK);
				break;
			case 'R':
				setcolor(GREEN, BLACK);
				break;
			default:
				setcolor(WHITE, BLACK);
				break;
			}
			cout << setw(2) << field.at(x).at(y).getStatus();
			setcolor(WHITE, BLACK);
		}
		cout << endl;
	}
	cout << "Step: " << steps << endl;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
