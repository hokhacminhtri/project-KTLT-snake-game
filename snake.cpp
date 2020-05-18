#include "game.h"

SNAKE* initSnake() {
	SNAKE* snake = (SNAKE*)malloc(sizeof(SNAKE));
	snake->length = 1;
	snake->body = (POS*)malloc(snake->length * sizeof(POS));
	snake->body[0].x = 5;
	snake->body[0].y = 5;
	snake->body[0].c = '1';
	snake->dir = 0;
	snake->tmpDir = 0;
	snake->prevEat = false;
	return snake;
}

void pushTopTail(SNAKE* snake, POS newTail) {
	POS* newBody = (POS*)realloc(snake->body, (snake->length + 1) * sizeof(POS));
	for (int i = 2; i < snake->length + 1; i++) {
		snake->body[i].x = snake->body[i - 1].x;
		snake->body[i].y = snake->body[i - 1].y;
	}
	if (newBody != NULL) {
		snake->body = newBody;
		snake->body[snake->length].x = newTail.x;
		snake->body[snake->length].y = newTail.y;
		snake->body[snake->length].c = newTail.c;
		snake->length++;
	}

}

void renderSnake(SNAKE* snake) {
	drawChar(snake->body[0].x, snake->body[0].y, headColor, snake->body[0].c);
	for (int i = 1; i < snake->length; i++) {
		drawChar(snake->body[i].x, snake->body[i].y, tailColor, snake->body[i].c);
	}
}
