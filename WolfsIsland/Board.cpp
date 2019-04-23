#include "pch.h"
#include "Board.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

Board::Board() {
	for (int y = 0; y < 20; y++) {
		vector<Cell> column;
		for (int x = 0; x < 20; x++) {
			Cell cell(x, y);
			column.push_back(cell);
		}
		field.push_back(column);
	}
}

Board::~Board() {}

void Board::show(int steps) {
	//system("CLS");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);

	COORD coord{ 0,0 }; //sets cursor position to (0;0)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {
			cout << setw(2) << field.at(x).at(y).getStatus();
		}
		cout << endl;
	}
	cout << "Step: " << steps;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
