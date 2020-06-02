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
	for (int i = y + 1; i < height + y; i++)
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

void Option(int option1, int option2) {
	if (option1 == 1) {
		if (option2 == 2) {
			GotoXY(25, 22);
			cout << " ";
			GotoXY(70, 22);
			cout << " ";
		}
		GotoXY(25, 20);
		cout << "[";
		GotoXY(50, 20);
		cout << "]";
	}
	if (option1 == 2) {
		if (option2 == 1) {
			GotoXY(25, 20);
			cout << " ";
			GotoXY(50, 20);
			cout << " ";
		}
		if (option2 == 3) {
			GotoXY(25, 24);
			cout << " ";
			GotoXY(50, 24);
			cout << " ";
		}
		GotoXY(25, 22);
		cout << "[";
		GotoXY(70, 22);
		cout << "]";
	}
	if (option1 == 3) {
		if (option2 == 2) {
			GotoXY(25, 22);
			cout << " ";
			GotoXY(70, 22);
			cout << " ";
		}
		if (option2 == 4) {
			GotoXY(25, 26);
			cout << " ";
			GotoXY(50, 26);
			cout << " ";
		}
		GotoXY(25, 24);
		cout << "[";
		GotoXY(50, 24);
		cout << "]";
	}
	if (option1 == 4) {
		if (option2 == 3) {
			GotoXY(25, 24);
			cout << " ";
			GotoXY(50, 24);
			cout << " ";
		}
		GotoXY(25, 26);
		cout << "[";
		GotoXY(50, 26);
		cout << "]";
	}
}

void Menu() {
	int option1 = 1;
	int option2 = 0;

	system("cls");

	TextColor(12);
	GotoXY(15, 4);
	cout << " __    _    _   _     ___     __  __        ______";
	TextColor(12);
	GotoXY(15, 5);
	cout << "|  \\  | |  | |_| |   /   \\   |  \\/  |      / ___  \\";
	TextColor(13);
	GotoXY(15, 6);
	cout << "|   \\ | |  |  _  |  /     \\  | |\\/| |      |_| /  /";
	TextColor(14);
	GotoXY(15, 7);
	cout << "| |\\ \\| |  | | | |  \\     /  | |  | |         /  /____";
	TextColor(10);
	GotoXY(15, 8);
	cout << "|_| \\ __|  |_| |_|   \\___/   |_|  |_|        /_______/";



	TextColor(13);
	GotoXY(30, 20);	
	cout << "PLAY GAME" << endl;
	GotoXY(30, 22);
	cout << "ABOUT (thong tin cac thanh vien nhom)" << endl;
	GotoXY(30, 24);
	cout << "LOAD GAME";
	GotoXY(30, 26);
	cout << "END GAME" << endl;

	Option(option1, option2);
	while (1) {
		int h;
		if (_kbhit()) {
			h = _getch();
			if (h == 13)
				break;
			if (h == 80) {
				if (option1 < 8) {
					option2 = option1;
					option1++;
					Option(option1, option2);
				}
			}
			if (h == 72) {
				if (option1 > 1) {
					option2 = option1;
					option1--;
					Option(option1, option2);
				}
			}
		}
	}

	if (option1 == 1) {
		system("cls");
		TextColor(10);

		drawBoard(0, 0, WIDTH_CONSOLE, HEIGHT_CONSOLE);
		NewGame();

		system("pause");
		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		Menu();
	}
	if (option1 == 2) {
		system("cls");
		TextColor(14);

		cout << "18120586 - Ho Hoang Thuong" << endl;
		cout << "18120609 - Ho Khac Minh Tri" << endl;
		cout << "18120598 - Huynh Gia Toai" << endl;
		cout << "18120322 - Luu Thien Duc" << endl;
		cout << "18120316 - Pham Ngoc Diep" << endl;
		cout << endl;

		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		Menu();
	}
	if (option1 == 3) {
		system("cls");
		TextColor(10);
		GotoXY(50, 10);
		string saveFile;
		cout << "Nhap ten file load: "; cin >> saveFile;
		SNAKE* snake = LoadGame(saveFile);
		system("cls");
		TextColor(10);
		drawBoard(0, 0, WIDTH_CONSOLE, HEIGHT_CONSOLE);
		NewGame(snake);



		system("pause");

		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		Menu();
		//load game
	}
	if (option1 == 4) {
		//thoat game
	}
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
	bool isQuit = false;
	TIMER timer;
	timer.currentTime = clock();
	timer.frameRate = double(1) / 15;
	timer.deltaTime = 0;
	SNAKE* snake = initSnake();
	POS fruit;// = { 3, 3, '8' };
	POS* gate = GenerateGate(snake);
	GenerateFruit(snake, fruit, snake->vt);
	renderSnake(snake);
	drawChar(fruit.x, fruit.y, 13, fruit.c);
	while (!isQuit) {
		if (timer.timeStep()) {
			Input(snake);
			Update(snake, fruit, gate, snake->vt);
			if (checkCollision(snake, gate))
				isQuit = true;
			Render(snake, fruit);
			Sleep(100 / snake->speed);
		}
	}
	deleteSnake(snake);
}

void NewGame(SNAKE* snake) { // Test
	bool isQuit = false;
	TIMER timer;
	timer.currentTime = clock();
	timer.frameRate = double(1) / 15;
	timer.deltaTime = 0;
	POS fruit;// = { 3, 3, '8' };
	POS* gate = GenerateGate(snake);
	GenerateFruit(snake, fruit, snake->vt);
	renderSnake(snake);
	drawChar(fruit.x, fruit.y, 13, fruit.c);
	while (!isQuit) {
		if (timer.timeStep()) {
			Input(snake);
			Update(snake, fruit, gate, snake->vt);
			if (checkCollision(snake, gate))
				isQuit = true;
			Render(snake, fruit);
			Sleep(100 / snake->speed);
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
	else if ((GetAsyncKeyState(saveGame) & 0x8000) != 0 || GetAsyncKeyState(saveGame) & 0x8000) {
		while (true)
			if (SaveGame(snake)) break;
		GotoXY(80, 11);
		system("pause");
		GotoXY(80, 10);
		cout << "                                 ";
		GotoXY(80, 11);
		cout << "                                 ";
	}
	if (snake->dir == up && snake->tmpDir == down) snake->dir = down;
	if (snake->dir == down && snake->tmpDir == up) snake->dir = up;
	if (snake->dir == left && snake->tmpDir == right) snake->dir = right;
	if (snake->dir == right && snake->tmpDir == left) snake->dir = left;
	snake->tmpDir = snake->dir;
	return 0;
}

void Update(SNAKE* snake, POS& fruit, POS* gate, int& vt) {
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
			if (snake->haveGate == true)
			{
				if ((snake->body[0].x == gate[1].x && snake->body[0].y == gate[1].y)
					|| (snake->body[0].x == gate[2].x && snake->body[0].y == gate[2].y))
				{
					enterGate(snake, gate);
					if ((gate[1].x == snake->body[snake->length - 1].x && gate[1].y == snake->body[snake->length - 1].y)
						|| gate[2].x == snake->body[snake->length - 1].x && gate[2].y == snake->body[snake->length - 1].y
						) {
						//	drawChar(gate[1].x,gate[1].y,green,space);
						renderGate(gate, space);
						newLevel(snake);
						GenerateFruit(snake, fruit, vt);
						drawChar(fruit.x, fruit.y, 13, fruit.c);
					}
				}
			}
		}
		else {
			snake->prevEat = false;
			pushTopTail(snake, fruit);
			//Tạo fruit hoặc tạo cổng
			if (snake->length % 8 == 0 && snake->length / 8 == snake->speed) {
				gate = GenerateGate(snake);
				snake->haveGate = true;
				fruit.x = 0;
				fruit.y = 0;
				renderGate(gate);
			}
			else {
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

