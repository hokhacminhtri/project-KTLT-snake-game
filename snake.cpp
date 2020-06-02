#include "game.h"

SNAKE* initSnake() {
	SNAKE* snake = (SNAKE*)malloc(sizeof(SNAKE));
	snake->length = 1;
	snake->body = (POS*)malloc(snake->length * sizeof(POS));
	srand((unsigned int)time(0));
	snake->body[0].x = rand() % (WIDTH_CONSOLE-1) + 1 ;
	snake->body[0].y = rand() % (HEIGHT_CONSOLE-1)+ 1;
	// sua lai head theo random
	snake->body[0].c = '1';
	snake->dir = 0;
	snake->tmpDir = 0;
	snake->prevEat = false;
	snake->speed=1;
	snake->haveGate=false;
	snake->vt = 0;
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
		delete snake;
	}
}

bool checkCollision(SNAKE* snake,POS* gate){
	
	if(snake->body[0].x<=0||snake->body[0].x>=WIDTH_CONSOLE)
		return true;

	if(snake->body[0].y<=0||snake->body[0].y>=HEIGHT_CONSOLE)
		return true;

	if(snake->dir==0)
		return false;	

	for(int i=3;i<snake->length;i++){
		if(snake->body[0].x==snake->body[i].x&&snake->body[0].y==snake->body[i].y)
			return true;
	}
	if (snake->haveGate == true)
	{
		if ((snake->body[0].x == gate[0].x && snake->body[0].y == gate[0].y) || (snake->body[0].x == gate[3].x && snake->body[0].y == gate[3].y))
			return true;
		if ((snake->body[0].x == gate[1].x && snake->body[0].y == gate[1].y-1) || (snake->body[0].x == gate[2].x && snake->body[0].y == gate[2].y-1))
			return true;
	}
	return false;
}

POS* GenerateGate(SNAKE* snake)
{
	POS* gate = (POS*)malloc(4 * sizeof(POS));
	//sua thanh random
	gate[0].x =  16; gate[0].y = 10;
	gate[1].x = 17; gate[1].y = 10;
	gate[2].x = 18; gate[2].y = 10;
	gate[3].x = 19; gate[3].y = 10;

	gate[0].c = static_cast<char>(219);
	gate[1].c = static_cast<char>(223);
	gate[2].c = static_cast<char>(223);
	gate[3].c = static_cast<char>(219);

	snake->haveGate = false;
	return gate;
}

void renderGate(POS* gate)
{
	for (int i = 0; i < GATE_SIZE; i++)
	{
		drawChar(gate[i].x, gate[i].y, tailColor, gate[i].c);
	}
}

void renderGate(POS* gate, char c)
{
	for (int i = 0; i < GATE_SIZE; i++)
	{
		drawChar(gate[i].x, gate[i].y, tailColor,c);
	}
}

void enterGate(SNAKE* snake,POS* gate){
	
	int lengthSnake=snake->length-1;
	snake->body[0].x=gate[1].x;
	snake->body[0].y=gate[1].y;
	snake->dir=0;
	
}
void newLevel(SNAKE* snake){
	snake->speed+=1;
	srand((unsigned int)time(0));
	snake->body[0].x = rand() % (WIDTH_CONSOLE-5) + 5 ;
	snake->body[0].y = rand() % (HEIGHT_CONSOLE-5)+ 5;
	for (int i = 1; i <= snake->length-1; i++) {
		snake->body[i].x = snake->body[0].x-1;
		snake->body[i].y = snake->body[0].y;
	}	
	snake->dir = 0;
	snake->tmpDir = 0;
	snake->haveGate=false;
}