#include "game.h"

// Ham tao vi tri cho Gate
POS POS_Gate(SNAKE* snake)
{
	POS temp;
	srand((unsigned int)time(0));
	do {
		temp.x = rand() % (WIDTH_CONSOLE - 2) / 2 + 1 + OFFSET_X;
		temp.y = rand() % (HEIGHT_CONSOLE - 2) / 2 + 1 + OFFSET_Y;
	} while (IsValid(snake, temp.x, temp.y) == false || IsValid(snake, temp.x + 1, temp.y) == false
		|| IsValid(snake, temp.x + 2, temp.y) == false || IsValid(snake, temp.x + 3, temp.y) == false);//vi tri gate khong trung voi snake

	return temp;
}


GAMEOBJECT* initGameObject() {
	GAMEOBJECT* gameObject = new GAMEOBJECT;	//khoi tao game object
	if (gameObject == NULL) return NULL;

	SNAKE* snake = initSnake(); // Khoi tao snake
	if (snake == NULL) return gameObject;
	gameObject->snake = snake;

	POS* gate = generateGate(gameObject->snake); // Khoi tao gate
	if (gate == NULL) return gameObject;
	gameObject->gate = gate;

	POS* fruit = new POS; // Khoi tao fruit
	if (fruit == NULL) return gameObject;
	generateFruit(gameObject->snake, fruit, gate);
	gameObject->fruit = fruit;

	return gameObject;
}

SNAKE* initSnake() {
	SNAKE* snake = (SNAKE*)malloc(sizeof(SNAKE));
	snake->length = 1;
	snake->body = (POS*)malloc(snake->length * sizeof(POS));
	srand((unsigned int)time(0));
	snake->body[0].x = rand() % (WIDTH_CONSOLE - 1) + 1 + OFFSET_X;
	snake->body[0].y = rand() % (HEIGHT_CONSOLE - 1) + 1 + OFFSET_Y;
	snake->body[0].c = '1';
	snake->dir = 0;
	snake->tmpDir = 0;
	snake->prevEat = false;
	snake->speed = 1;
	snake->haveGate = false;
	snake->vt = 1;
	return snake;
}

void generateFruit(SNAKE* snake, POS* fruit, POS* gate) {
	int x, y;
	srand((unsigned int)time(NULL));
	do {
		x = rand() % (WIDTH_CONSOLE - 2) + 1 + OFFSET_X;
		y = rand() % (HEIGHT_CONSOLE - 2) + 1 + OFFSET_Y;
	} while (IsValid(snake, x, y) == false || IsValid1(gate, x, y) == false);
	fruit->x = x;
	fruit->y = y;
	fruit->c = char(fruit_name[snake->vt]);
	snake->vt++;
}

POS* generateGate(SNAKE* snake) {
	if (snake == NULL) return NULL;
	POS* gate = new POS[4];
	if (gate == NULL) return NULL;

	POS position = POS_Gate(snake);

	gate[0].x = position.x + OFFSET_X; gate[0].y = position.y + OFFSET_Y;
	gate[1].x = position.x + 1 + OFFSET_X; gate[1].y = position.y + OFFSET_Y;
	gate[2].x = position.x + 2 + OFFSET_X; gate[2].y = position.y + OFFSET_Y;
	gate[3].x = position.x + 3 + OFFSET_X; gate[3].y = position.y + OFFSET_Y;

	gate[0].c = static_cast<char>(219);
	gate[1].c = static_cast<char>(223);
	gate[2].c = static_cast<char>(223);
	gate[3].c = static_cast<char>(219);

	snake->haveGate = false;

	return gate;
}

void deleteGameObject(GAMEOBJECT* gameObject) {
	if (gameObject != NULL) {
		if (gameObject->snake != NULL) {
			delete[] gameObject->snake;
		}
		if (gameObject->fruit != NULL) {
			delete gameObject->fruit;
		}
		if (gameObject->gate != NULL) {
			delete[] gameObject->gate;
		}
		delete gameObject;
	}
}

void renderSnake(SNAKE* snake) {
	drawChar(snake->body[0].x, snake->body[0].y, headColor, snake->body[0].c); // Ve head
	for (int i = 1; i < snake->length; i++) {
		drawChar(snake->body[i].x, snake->body[i].y, tailColor, snake->body[i].c); // ve tail
	}
	TextColor(9);
	GotoXY(WIDTH_CONSOLE + 4 + OFFSET_X, 3);
	cout << "SCORE: " << snake->length - 1;
	GotoXY(WIDTH_CONSOLE + 4 + OFFSET_X, 5);
	cout << "SPEED: " << snake->speed;
	TextColor(7);

	GuideTable();
}

void renderFruit(POS* fruit) {
	drawChar(fruit->x, fruit->y, fruitColor, fruit->c);
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
		drawChar(gate[i].x, gate[i].y, tailColor, c);
	}
}

void DeathEffect(SNAKE* snake)
{
	for (int i = snake->length; i >= 0; i--) {
		drawChar(snake->body[i].x, snake->body[i].y, tailColor, ' ');
		Sleep(60);
	}
	drawChar(snake->body[0].x, snake->body[0].y, red, '*');
	Sleep(120);
	for (int i = 0; i < 7; i++) {
		if (i == 0)
		{
			drawChar(snake->body[0].x, snake->body[0].y, red, '#');
			drawChar(snake->body[0].x - 1, snake->body[0].y, red, '*');
			drawChar(snake->body[0].x + 1, snake->body[0].y, red, '*');
			Sleep(120);
		}
		if (i == 1)
		{
			drawChar(snake->body[0].x, snake->body[0].y, red, '@');
			drawChar(snake->body[0].x - 1, snake->body[0].y, red, '#');
			drawChar(snake->body[0].x + 1, snake->body[0].y, red, '#');
			drawChar(snake->body[0].x, snake->body[0].y - 1, red, '#');
			drawChar(snake->body[0].x, snake->body[0].y + 1, red, '#');
			drawChar(snake->body[0].x - 1, snake->body[0].y - 1, red, '*');
			drawChar(snake->body[0].x + 1, snake->body[0].y - 1, red, '*');
			drawChar(snake->body[0].x - 1, snake->body[0].y + 1, red, '*');
			drawChar(snake->body[0].x + 1, snake->body[0].y + 1, red, '*');
			Sleep(120);
		}
		if (i == 2)
		{
			{
				drawChar(snake->body[0].x, snake->body[0].y, red, '@');
				drawChar(snake->body[0].x - 1, snake->body[0].y, red, '#');
				drawChar(snake->body[0].x - 2, snake->body[0].y, red, '#');
				drawChar(snake->body[0].x - 3, snake->body[0].y, red, '*');
				drawChar(snake->body[0].x + 1, snake->body[0].y, red, '#');
				drawChar(snake->body[0].x + 2, snake->body[0].y, red, '#');
				drawChar(snake->body[0].x + 3, snake->body[0].y, red, '*');
				drawChar(snake->body[0].x, snake->body[0].y + 1, red, '#');
				drawChar(snake->body[0].x, snake->body[0].y + 2, red, '#');
				drawChar(snake->body[0].x, snake->body[0].y + 3, red, '*');
				drawChar(snake->body[0].x, snake->body[0].y - 1, red, '#');
				drawChar(snake->body[0].x, snake->body[0].y - 2, red, '#');
				drawChar(snake->body[0].x, snake->body[0].y - 3, red, '*');
				drawChar(snake->body[0].x - 1, snake->body[0].y - 1, red, '#');
				drawChar(snake->body[0].x - 2, snake->body[0].y - 1, red, '*');
				drawChar(snake->body[0].x - 3, snake->body[0].y - 1, red, '*');
				drawChar(snake->body[0].x + 1, snake->body[0].y - 1, red, '#');
				drawChar(snake->body[0].x + 2, snake->body[0].y - 1, red, '*');
				drawChar(snake->body[0].x + 3, snake->body[0].y - 1, red, '*');
				drawChar(snake->body[0].x - 1, snake->body[0].y - 2, red, '#');
				drawChar(snake->body[0].x - 2, snake->body[0].y - 2, red, '*');
				drawChar(snake->body[0].x + 1, snake->body[0].y - 2, red, '#');
				drawChar(snake->body[0].x + 2, snake->body[0].y - 2, red, '*');
				drawChar(snake->body[0].x - 1, snake->body[0].y + 1, red, '#');
				drawChar(snake->body[0].x - 2, snake->body[0].y + 1, red, '*');
				drawChar(snake->body[0].x - 3, snake->body[0].y + 1, red, '*');
				drawChar(snake->body[0].x + 1, snake->body[0].y + 1, red, '#');
				drawChar(snake->body[0].x + 2, snake->body[0].y + 1, red, '*');
				drawChar(snake->body[0].x + 3, snake->body[0].y + 1, red, '*');
				drawChar(snake->body[0].x - 1, snake->body[0].y + 2, red, '#');
				drawChar(snake->body[0].x - 2, snake->body[0].y + 2, red, '*');
				drawChar(snake->body[0].x + 1, snake->body[0].y + 2, red, '#');
				drawChar(snake->body[0].x + 2, snake->body[0].y + 2, red, '*');
			}
			Sleep(120);
		}
		if (i == 3)
		{
			drawChar(snake->body[0].x, snake->body[0].y, tailColor, ' ');
			Sleep(120);
		}
		if (i == 4)
		{
			drawChar(snake->body[0].x - 1, snake->body[0].y, tailColor, ' ');
			drawChar(snake->body[0].x + 1, snake->body[0].y, tailColor, ' ');
			Sleep(120);
		}
		if (i == 5)
		{
			drawChar(snake->body[0].x, snake->body[0].y - 1, tailColor, ' ');
			drawChar(snake->body[0].x, snake->body[0].y + 1, tailColor, ' ');
			drawChar(snake->body[0].x - 1, snake->body[0].y - 1, tailColor, ' ');
			drawChar(snake->body[0].x + 1, snake->body[0].y - 1, tailColor, ' ');
			drawChar(snake->body[0].x - 1, snake->body[0].y + 1, tailColor, ' ');
			drawChar(snake->body[0].x + 1, snake->body[0].y + 1, tailColor, ' ');
			Sleep(120);
		}
		if (i == 6)
		{
			{
				drawChar(snake->body[0].x - 2, snake->body[0].y, tailColor, ' ');
				drawChar(snake->body[0].x - 3, snake->body[0].y, tailColor, ' ');
				drawChar(snake->body[0].x + 2, snake->body[0].y, tailColor, ' ');
				drawChar(snake->body[0].x + 3, snake->body[0].y, tailColor, ' ');
				drawChar(snake->body[0].x, snake->body[0].y + 2, tailColor, ' ');
				drawChar(snake->body[0].x, snake->body[0].y + 3, tailColor, ' ');
				drawChar(snake->body[0].x, snake->body[0].y - 2, tailColor, ' ');
				drawChar(snake->body[0].x, snake->body[0].y - 3, tailColor, ' ');
				drawChar(snake->body[0].x - 2, snake->body[0].y - 1, tailColor, ' ');
				drawChar(snake->body[0].x - 3, snake->body[0].y - 1, tailColor, ' ');
				drawChar(snake->body[0].x + 2, snake->body[0].y - 1, tailColor, ' ');
				drawChar(snake->body[0].x + 3, snake->body[0].y - 1, tailColor, ' ');
				drawChar(snake->body[0].x - 1, snake->body[0].y - 2, tailColor, ' ');
				drawChar(snake->body[0].x - 2, snake->body[0].y - 2, tailColor, ' ');
				drawChar(snake->body[0].x + 1, snake->body[0].y - 2, tailColor, ' ');
				drawChar(snake->body[0].x + 2, snake->body[0].y - 2, tailColor, ' ');
				drawChar(snake->body[0].x - 2, snake->body[0].y + 1, tailColor, ' ');
				drawChar(snake->body[0].x - 3, snake->body[0].y + 1, tailColor, ' ');
				drawChar(snake->body[0].x + 2, snake->body[0].y + 1, tailColor, ' ');
				drawChar(snake->body[0].x + 3, snake->body[0].y + 1, tailColor, ' ');
				drawChar(snake->body[0].x - 1, snake->body[0].y + 2, tailColor, ' ');
				drawChar(snake->body[0].x - 2, snake->body[0].y + 2, tailColor, ' ');
				drawChar(snake->body[0].x + 1, snake->body[0].y + 2, tailColor, ' ');
				drawChar(snake->body[0].x + 2, snake->body[0].y + 2, tailColor, ' ');
			}
			Sleep(120);
		}
	}
}

void pushTopTail(SNAKE* snake, POS* newTail) { // Tang kich thuoc khi an fruit
	POS* newBody = (POS*)realloc(snake->body, (snake->length + 1) * sizeof(POS));
	if (newBody != NULL) {
		newBody[snake->length].c = newTail->c;
		for (int i = snake->length; i >= 2; i--) {
			newBody[i].x = newBody[i - 1].x;
			newBody[i].y = newBody[i - 1].y;
		}
		newBody[1].x = newTail->x;
		newBody[1].y = newTail->y;
		snake->body = newBody;
		snake->length++;
	}
}

void deleteSnake(SNAKE* snake) {
	if (snake != NULL)
	{
		delete[]snake->body;
		delete snake;
	}
}

bool checkCollision(SNAKE* snake, POS* gate) {

	if (snake->body[0].x <= 25 || snake->body[0].x >= WIDTH_CONSOLE + OFFSET_X)
		return true;

	if (snake->body[0].y <= 3 || snake->body[0].y >= HEIGHT_CONSOLE + OFFSET_Y)
		return true;

	if (snake->dir == 0)
		return false;

	for (int i = 3; i < snake->length; i++) {
		if (snake->body[0].x == snake->body[i].x && snake->body[0].y == snake->body[i].y)
			return true;
	}
	if (snake->haveGate == true)
	{
		if ((snake->body[0].x == gate[0].x && snake->body[0].y == gate[0].y) || (snake->body[0].x == gate[3].x && snake->body[0].y == gate[3].y))
			return true;
		if ((snake->body[0].x == gate[1].x && snake->body[0].y == gate[1].y - 1) || (snake->body[0].x == gate[2].x && snake->body[0].y == gate[2].y - 1))
			return true;
	}
	return false;
}

void enterGate(SNAKE* snake, POS* gate) {
	int lengthSnake = snake->length - 1;
	snake->body[0].x = gate[1].x;
	snake->body[0].y = gate[1].y;
	snake->dir = 0;

}

void newLevel(SNAKE* snake) {
	PlaySound(TEXT("NextLevel"), NULL, SND_ASYNC);
	snake->speed += 1;
	if (snake->vt == strlen(fruit_name)) snake->vt = 0;	//khi end day mssv thi quay lai vi tri ban dau
	if (snake->speed == MAX_LEVEL) { //khi max level thi reset level
		snake->speed = 1;
		POS* newBody = (POS*)realloc(snake->body, 1 * sizeof(POS));
		if (newBody != NULL) {
			newBody->c = '1';
			snake->body = newBody;
			snake->length = 1;
			snake->vt = 1;
		}
	}
	srand((unsigned int)time(0));
	snake->body[0].x = rand() % (WIDTH_CONSOLE - 5) + 5 + OFFSET_X;
	snake->body[0].y = rand() % (HEIGHT_CONSOLE - 5) + 5 + OFFSET_Y;
	for (int i = 1; i <= snake->length - 1; i++) {
		snake->body[i].x = snake->body[0].x - 1;
		snake->body[i].y = snake->body[0].y;
	}
	snake->dir = 0;
	snake->tmpDir = 0;
	snake->haveGate = false;
}
