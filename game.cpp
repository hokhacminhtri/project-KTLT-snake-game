#include "game.h"

void DrawBoard(int x, int y, int width, int height)
{
	GotoXY(x, y);
	cout << static_cast<char>(220);
	for (int i = 1; i < width; i++)
		cout << static_cast<char>(220);
	cout << static_cast<char>(220);
	GotoXY(x, height + y);
	cout << static_cast<char>(223);
	for (int i = 0; i < width; i++)
		cout << static_cast<char>(223);

	for (int i = y + 1; i < height + y; i++)
	{
		GotoXY(x, i);
		cout << static_cast<char>(219);
		GotoXY(x + width, i);
		cout << static_cast<char>(219);
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

		DrawBoard(OFFSET_X, OFFSET_Y, WIDTH_CONSOLE, HEIGHT_CONSOLE);
		NewGame();


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
		cout << "Nhap ten file load (Nhap duoi file .txt): "; cin >> saveFile;
		GAMEOBJECT* gameObject = LoadGame(saveFile);
		system("cls");
		TextColor(10);
		DrawBoard(OFFSET_X, OFFSET_Y, WIDTH_CONSOLE, HEIGHT_CONSOLE);
		NewGame(gameObject);
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
	GAMEOBJECT* gameObject = initGameObject();
	if (gameObject != NULL && gameObject->snake != NULL) {
		SNAKE* snake = gameObject->snake;
		POS* fruit = gameObject->fruit;
		POS* gate = gameObject->gate;
		if (snake != NULL && fruit != NULL && gate != NULL) {
			renderSnake(gameObject->snake);
			renderFruit(gameObject->fruit);
			_getch();
			while (!isQuit) {
				if (timer.timeStep()) {
					if (Input(gameObject) == true) break;
					Update(gameObject);
					if (checkCollision(gameObject->snake, gameObject->gate)) {
						isQuit = true;		//xu ly ket thuc game
						//Hieu ung khi ran chet
						DeathEffect(gameObject->snake);
						if (EndGame(gameObject->snake) == true) {
							GotoXY(80, 10);
							exit(0);	//thoat chuong trinh
						}
					}
					Render(gameObject);
					Sleep(100 / gameObject->snake->speed);
				}
			}
		}
	}
	deleteGameObject(gameObject);
}

void NewGame(GAMEOBJECT* gameObject) { // Test
	bool isQuit = false;
	TIMER timer;
	timer.currentTime = clock();
	timer.frameRate = double(1) / 15;
	timer.deltaTime = 0;
	if (gameObject != NULL && gameObject->snake != NULL) {
		SNAKE* snake = gameObject->snake;
		POS* fruit = gameObject->fruit;
		POS* gate = gameObject->gate;
		if (snake != NULL && fruit != NULL && gate != NULL) {
			renderSnake(gameObject->snake);
			if (snake->haveGate == true) renderGate(gate);
			else renderFruit(gameObject->fruit);
			_getch();
			while (!isQuit) {
				if (timer.timeStep()) {
					if (Input(gameObject) == true) break;
					Update(gameObject);
					if (checkCollision(gameObject->snake, gameObject->gate)) {
						isQuit = true;
						DeathEffect(gameObject->snake);
						if (EndGame(gameObject->snake) == true) {
							GotoXY(80, 10);
							exit(0);	//thoat chuong trinh
						}
					}
					Render(gameObject);
					Sleep(100 / gameObject->snake->speed);
				}
			}
		}
	}
	deleteGameObject(gameObject);
}

bool Input(GAMEOBJECT* gameObject) {
	if ((GetAsyncKeyState(VK_UP) & 0x8000) != 0 || (GetAsyncKeyState(VK_UP) & 0x8000)) gameObject->snake->dir = up;
	else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) != 0 || (GetAsyncKeyState(VK_LEFT) & 0x8000)) gameObject->snake->dir = left;
	else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) != 0 || GetAsyncKeyState(VK_DOWN) & 0x8000) gameObject->snake->dir = down;
	else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) != 0 || GetAsyncKeyState(VK_LEFT) & 0x8000) gameObject->snake->dir = right;

	if (_kbhit()) {
		int n = _getch();
		if (n == int('t')) {	//tai game
			GotoXY(OFFSET_X + 20, 25);
			string saveFile;
			cout << "Nhap ten file load: ";
			cin >> saveFile;
			GAMEOBJECT* gameObject = LoadGame(saveFile);
			system("cls");
			TextColor(10);
			DrawBoard(OFFSET_X, OFFSET_Y, WIDTH_CONSOLE, HEIGHT_CONSOLE);
			NewGame(gameObject);

			Menu();
		}
		else if (n == int('p')) { //dung game khi dang choi (pause)
			GotoXY(OFFSET_X + WIDTH_CONSOLE / 2 - 2, OFFSET_Y - 1);
			TextColor(10);
			cout << "PAUSE";
			while (true)
				if ((GetAsyncKeyState(continueGame) & 0x8000) != 0 || GetAsyncKeyState(continueGame) & 0x8000) {
					GotoXY(OFFSET_X + WIDTH_CONSOLE / 2 - 2, OFFSET_Y - 1);
					cout << "     ";
					break;
				}
		}
		else if (n == (int)'x') {	//tro ve man hinh menu khi dang choi
			return true;
		}
		else if (n == (int)'l') {	//luu game
			while (true)
				if (SaveGame(gameObject)) break;
			GotoXY(OFFSET_X + 20, 26);
			system("pause");
			GotoXY(OFFSET_X + 20, 25);
			cout << "                                            ";
			GotoXY(OFFSET_X + 20, 26);
			cout << "                                            ";
		}
		else if (n == 'm') {	//tat nhac
			PlaySound(NULL, NULL, NULL);
		}
		else if (n == 'u') {
			PlaySound(TEXT("GameMusic"), NULL, SND_ASYNC);
		}
	}
	if (gameObject->snake->dir == up && gameObject->snake->tmpDir == down) gameObject->snake->dir = down;
	if (gameObject->snake->dir == down && gameObject->snake->tmpDir == up) gameObject->snake->dir = up;
	if (gameObject->snake->dir == left && gameObject->snake->tmpDir == right) gameObject->snake->dir = right;
	if (gameObject->snake->dir == right && gameObject->snake->tmpDir == left) gameObject->snake->dir = left;
	gameObject->snake->tmpDir = gameObject->snake->dir;

	return 0;
}

void Update(GAMEOBJECT* gameObject) {
	SNAKE* snake = gameObject->snake;
	POS* fruit = gameObject->fruit;
	POS* gate = gameObject->gate;
	if (snake->length == 1 && snake->prevEat == false) {
		drawChar(snake->body[0].x, snake->body[0].y, headColor, space);
	}
	else {
		if (snake->prevEat == false) {
			drawChar(snake->body[snake->length - 1].x, snake->body[snake->length - 1].y, tailColor, space);
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
						generateFruit(snake, fruit);
						renderFruit(fruit);
					}
				}
			}
		}
		else {
			snake->prevEat = false;
			pushTopTail(snake, fruit);
			//Tạo fruit hoặc tạo cổng
			if (snake->length % 8 == 0 && snake->length / 8 == snake->speed) {
				gate = generateGate(snake);
				snake->haveGate = true;
				fruit->x = 0;
				fruit->y = 0;
				renderGate(gate);
			}
			else {
				generateFruit(gameObject->snake, gameObject->fruit);
				renderFruit(fruit);
			}

		}
	}

	if (snake->dir == up) snake->body[0].y--;
	else if (snake->dir == left) snake->body[0].x--;
	else if (snake->dir == down) snake->body[0].y++;
	else if (snake->dir == right) snake->body[0].x++;
	if (snake->body[0].x == fruit->x && snake->body[0].y == fruit->y) {
		snake->prevEat = true;
	}
}

void Render(GAMEOBJECT* gameObject) {
	SNAKE* snake = gameObject->snake;
	renderSnake(snake);
}

bool EndGame(SNAKE* snake)
{
	PlaySound(TEXT("GameOver"), NULL, SND_ASYNC);
	char key;
	GotoXY(WIDTH_CONSOLE / 2 + OFFSET_X - 5, HEIGHT_CONSOLE / 2 - 3 + OFFSET_Y - 2);
	cout << "GAME OVER!";
	GotoXY(WIDTH_CONSOLE / 2 + OFFSET_X - 10, HEIGHT_CONSOLE / 2 + OFFSET_Y - 2);
	cout << "DIEM CUA BAN LA: " << snake->length - 1;
	GotoXY(WIDTH_CONSOLE / 2 + OFFSET_X - 10, HEIGHT_CONSOLE / 2 + 3 + OFFSET_Y - 2);
	cout << "Nhap 0 de thoat game >> ";
	cin >> key;
	if (key == '0')
		return true;
	return false;
}

void GuideTable() {
	TextColor(rand() % 14 + 1);
	GotoXY(WIDTH_CONSOLE + 5 + OFFSET_X, 9);
	cout << "====================";
	TextColor(rand() % 14 + 1);
	GotoXY(WIDTH_CONSOLE + 5 + OFFSET_X, 11);
	cout << "Nhan (t) de tai game (Nhap duoi file .txt)" << endl;
	TextColor(rand() % 14 + 1);
	GotoXY(WIDTH_CONSOLE + 5 + OFFSET_X, 13);
	cout << "Nhan (l) de luu game (Nhap duoi file .txt)" << endl;
	TextColor(rand() % 14 + 1);
	GotoXY(WIDTH_CONSOLE + 5 + OFFSET_X, 15);
	cout << "Nhan (m) de tat nhac" << endl;
	TextColor(rand() % 14 + 1);
	GotoXY(WIDTH_CONSOLE + 5 + OFFSET_X, 17);
	cout << "Nhan (u) de bat nhac" << endl;
	TextColor(rand() % 14 + 1);
	GotoXY(WIDTH_CONSOLE + 5 + OFFSET_X, 19);
	cout << "Nhan (x) de thoat game khi dang choi" << endl;
}


