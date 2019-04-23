#include "pch.h"
#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() {
	stepsCount = 0;
}
Game::~Game() {}

void Game::makestep() {
	stepsCount++;
}
void Game::showboard() {
	gameboard.show(stepsCount);
}