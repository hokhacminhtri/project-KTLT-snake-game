#pragma once

struct POS {
	int x;
	int y;
	char c;
};

struct SNAKE {
	POS* body;
	int length;
	int dir;
	int tmpDir;
	bool prevEat;
};

SNAKE* initSnake() ;
void pushTopTail(SNAKE* snake, POS newTail);
void renderSnake(SNAKE* snake);
