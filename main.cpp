// DoAnKTLT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//g++ main.cpp game.cpp parameter.cpp snake.cpp timer.cpp -o play

#include "game.h"

int main() {
	PlaySound(TEXT("GameMusic"), NULL, SND_ASYNC);
	OpenGame();
	return 0;
}
