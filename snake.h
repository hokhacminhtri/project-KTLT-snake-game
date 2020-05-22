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
	int speed;
	bool haveGate;
};

SNAKE* initSnake();
void pushTopTail(SNAKE* snake, POS newTail);
void renderSnake(SNAKE* snake);
void deleteSnake(SNAKE* snake);
bool checkCollision(SNAKE* snake);//Kiem tra va cham
void enterGate(SNAKE* snake,POS gate);
void newLevel(SNAKE* snake);

