#include "game.h"

void drawBoard(int x, int y, int width, int height)
{
	GotoXY(x, y);
	cout << 'X';
	for (int i = 1; i < width; i++)
		cout << 'X';
	cout << 'X';
	GotoXY(x, height + y);
	cout << 'X';
	for (int i = 0; i < width; i++)
		cout << 'X';
	cout << 'X';
	for(int i=y+1;i<height+y;i++)
	{
		GotoXY(x, i);
		cout << 'X';
		GotoXY(x + width, i);
		cout << 'X';
	}
}
void Loading() {
	TextColor(12);
	GotoXY(25, 12);
	cout << "*      *****   ***   ****   *****  *   *   ***          ";
	TextColor(13);
	GotoXY(25, 13);
	cout << "*      *   *  *   *  *   *    *    **  *  *             ";
	TextColor(9);
	GotoXY(25, 14);
	cout << "*      *   *  *****  *   *    *    * * *  *  **         ";
	TextColor(15);
	GotoXY(25, 15);
	cout << "*      *   *  *   *  *   *    *    *  **  *   *         ";
	TextColor(11);
	GotoXY(25, 16);
	cout << "*****  *****  *   *  ****   *****  *   *   ***   * * * *";
	for (int i = 1; i <= 80; i++)
	{
		TextColor(202);
		GotoXY(i + 5, 22);
		cout << char(219);
		TextColor(202);
		GotoXY(i + 5, 23);
		cout << char(219);
		Sleep(25);
	}
	TextColor(7);
}

void Menu() {
	int choose;

	do {
		system("cls");
		cout << "1. Play Game" << endl;
		cout << "2. About (thong tin cac thanh vien nhom)" << endl;
		cout << "0. Thoat chuong trinh" << endl;

		cout << "\nChon bai: " << endl;
		cin >> choose;
		system("cls");

		switch (choose) {
		case 1: {
			drawBoard(0,0,WIDTH_CONSOLE,HEIGHT_CONSOLE);
			NewGame();
			break;
		}
		case 2: {
			cout << "18120586 - Ho Hoang Thuong" << endl;
			cout << "18120609 - Ho Khac Minh Tri" << endl;
			cout << "18120598 - Huynh Gia Toai" << endl;
			cout << "18120322 - Luu Thien Duc" << endl;
			cout << "18120316 - Pham Ngoc Diep" << endl;

			cout << endl;
			system("pause");
			break;
		}
		case 0: {
			break;
		}
		}
	} while (choose != 0);
}

void OpenGame() {
	Loading();
	Sleep(200);
	system("cls");

	Menu();
	Sleep(100);
	system("cls");

	system("pause");
}

void NewGame() {
	bool isQuit=false;
	TIMER timer;
	timer.currentTime = clock();
	timer.frameRate = double(1) / 15;
	timer.deltaTime = 0;
	SNAKE* snake = initSnake();
	int vt = 0;
	POS fruit;// = { 3, 3, '8' };
	POS gate;
	GenerateFruit(snake, fruit, vt);
	renderSnake(snake);
	drawChar(fruit.x, fruit.y, 13, fruit.c);
	while (!isQuit) {
		if (timer.timeStep()) {
			Input(snake);
			Update(snake, fruit, gate, vt);
			if(checkCollision(snake))
				isQuit=true;
			Render(snake, fruit);
			Sleep(100/snake->speed);
		}
	}
	deleteSnake(snake);
}

int Input(SNAKE* snake) {
	if ((GetAsyncKeyState(VK_UP) & 0x8000) != 0 || (GetAsyncKeyState(VK_UP) & 0x8000)) snake->dir = up;
	else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) != 0 || (GetAsyncKeyState(VK_LEFT) & 0x8000)) snake->dir = left;
	else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) != 0 || GetAsyncKeyState(VK_DOWN) & 0x8000) snake->dir = down;
	else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) != 0 || GetAsyncKeyState(VK_LEFT) & 0x8000) snake->dir = right;
	else if ((GetAsyncKeyState(pauseGame) & 0x8000) != 0 || GetAsyncKeyState(pauseGame) & 0x8000) {
		while (true)
			if ((GetAsyncKeyState(continueGame) & 0x8000) != 0 || GetAsyncKeyState(continueGame) & 0x8000) break;
	}
	else if ((GetAsyncKeyState(exitGame) & 0x8000) != 0 || GetAsyncKeyState(exitGame) & 0x8000) return 1;

	if (snake->dir == up && snake->tmpDir == down) snake->dir = down;
	if (snake->dir == down && snake->tmpDir == up) snake->dir = up;
	if (snake->dir == left && snake->tmpDir == right) snake->dir = right;
	if (snake->dir == right && snake->tmpDir == left) snake->dir = left;
	snake->tmpDir = snake->dir;
	return 0;
}

void Update(SNAKE* snake, POS& fruit,POS& gate, int& vt) {
	if (snake->length == 1 && snake->prevEat == false) {
		drawChar(snake->body[0].x, snake->body[0].y, headColor, space);
	}
	else {
		if (snake->prevEat == false) {
			drawChar(snake->body[snake->length - 1].x, snake->body[snake->length - 1].y, green, space);
			for (int i = snake->length - 1; i >= 1; i--) {
				snake->body[i].x = snake->body[i - 1].x;
				snake->body[i].y = snake->body[i - 1].y;
			}

			if (snake->body[0].x == gate.x && snake->body[0].y == gate.y) {
				enterGate(snake,gate);
				if(gate.x==snake->body[snake->length - 1].x&&gate.y==snake->body[snake->length - 1].y){
					drawChar(gate.x,gate.y,green,space);
					newLevel(snake);
					GenerateFruit(snake, fruit, vt);
					drawChar(fruit.x, fruit.y, 13, fruit.c);
				}
			}
		}
		else {
			snake->prevEat = false;
			pushTopTail(snake, fruit);
			//Tạo fruit hoặc tạo cổng
			if(snake->length%8==0 && snake->length/8==snake->speed){
				CreateGate(snake,gate);
				fruit.x=0;
				fruit.y=0;
				drawChar(gate.x,gate.y,green,gate.c);
			}
			else{
				GenerateFruit(snake, fruit, vt);
				drawChar(fruit.x, fruit.y, 13, fruit.c);
			}
			
		}
	}

	if (snake->dir == up) snake->body[0].y--;
	else if (snake->dir == left) snake->body[0].x--;
	else if (snake->dir == down) snake->body[0].y++;
	else if (snake->dir == right) snake->body[0].x++;
	if (snake->body[0].x == fruit.x && snake->body[0].y == fruit.y) {
		snake->prevEat = true;
	}
	
}

void Render(SNAKE* snake, POS& fruit) {
	drawChar(snake->body[0].x, snake->body[0].y, headColor, snake->body[0].c);
	for (int i = 1; i < snake->length; i++) {
		drawChar(snake->body[i].x, snake->body[i].y, tailColor, snake->body[i].c);
	}
}

