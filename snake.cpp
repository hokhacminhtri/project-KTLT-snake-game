#include "game.h"

SNAKE* initSnake() {
	SNAKE* snake = (SNAKE*)malloc(sizeof(SNAKE));
	snake->length = 1;
	snake->body = (POS*)malloc(snake->length * sizeof(POS));
	srand((unsigned int)time(0));
	snake->body[0].x = rand() % (WIDTH_CONSOLE) + 1 ;
	snake->body[0].y = rand() % (HEIGHT_CONSOLE )+ 1;
	// sua lai head theo random
	snake->body[0].c = '1';
	snake->dir = 0;
	snake->tmpDir = 0;
	snake->prevEat = false;
	return snake;
}

void pushTopTail(SNAKE* snake, POS newTail) {
	POS* newBody = (POS*)realloc(snake->body, (snake->length + 1) * sizeof(POS));
	if (newBody != NULL) {
		newBody[snake->length].c = newTail.c;
		for (int i = snake->length; i >= 2; i--) {
			newBody[i].x = newBody[i - 1].x;
			newBody[i].y = newBody[i - 1].y;
		}
		newBody[1].x = newTail.x;
		newBody[1].y = newTail.y;
		snake->body = newBody;
		snake->length++;
	}
}

void renderSnake(SNAKE* snake) {
	drawChar(snake->body[0].x, snake->body[0].y, headColor, snake->body[0].c);
	for (int i = 1; i < snake->length; i++) {
		drawChar(snake->body[i].x, snake->body[i].y, tailColor, snake->body[i].c);
	}
}

void deleteSnake(SNAKE* snake) {
	if (snake != NULL)
	{
		delete[]snake->body;
		delete[]snake;
	}
}
