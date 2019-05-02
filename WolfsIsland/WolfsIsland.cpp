#include "pch.h"
#include <iostream>
#include <ctime>
#include "Game.h"
#include <random>
#include "Utils.h"

using namespace std;

int main() {
	time_t t;
	srand((int)time(NULL));
	t = clock();
	bool exit = false;
	float speed = 1; //steps per second
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