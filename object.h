#pragma once

#ifndef _OBJECT_
#define _OBJECT_

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
	int vt;
};

struct GAMEOBJECT {
	SNAKE* snake;
	POS* fruit;
	POS* gate;
};

GAMEOBJECT* initGameObject();
SNAKE* initSnake();
void generateFruit(SNAKE* snake, POS* fruit, POS* gate);
POS* generateGate(SNAKE* snake);
void deleteGameObject(GAMEOBJECT* gameObject);

void renderSnake(SNAKE* snake);
void renderFruit(POS* fruit);
void renderGate(POS* gate);
void renderGate(POS* gate, char c);
void DeathEffect(SNAKE* snake);

void pushTopTail(SNAKE* snake, POS* newTail);
bool checkCollision(SNAKE* snake, POS* gate);//Kiem tra va cham
void enterGate(SNAKE* snake, POS* gate);
void newLevel(SNAKE* snake);

#endif // !_OBJECT_


