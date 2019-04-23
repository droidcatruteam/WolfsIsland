#include "pch.h"
#include <iostream>
#include <ctime>
#include "Game.h"
using namespace std;

int main() {
	time_t t;
	t = clock();
	bool exit = false;
	int speed = 1; //steps per second
	Game game;

	cout << "Enter game speed: ";
	cin >> speed;
	
	while (!exit) {
		if (clock() - t >= 1000 / speed) {
			game.makestep();
			game.showboard();
			t = clock();
		}
	}
}