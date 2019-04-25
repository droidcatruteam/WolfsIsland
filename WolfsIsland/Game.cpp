#include "pch.h"
#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() {
	stepsCount = 0;
}
Game::~Game() {}

void Game::makestep() {
	gameboard.moveWolfs();
	gameboard.show(stepsCount);
	gameboard.moveRabbits();
	//gameboard.show(stepsCount);
	//gameboard.reproductRabbits();
	stepsCount++;
}
void Game::showboard() {
	gameboard.show(stepsCount);
}