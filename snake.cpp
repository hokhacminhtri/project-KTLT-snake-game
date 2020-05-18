#include "snake.h"
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Ham to mau
void TextColor(int color)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, color);
}

/***************Cac ham tao giao dien game***************/
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
	int n;
	int choose;

	do {
		system("cls");
		cout << "1. Play Game" << endl;
		cout << "2. About (thong tin cac thanh vien nhom)" << endl;
		cout << "0. Thoat chuong trinh" << endl;

		cout << "\nChon bai: " << endl;
		cin >> choose;
		cout << endl;

		switch (choose) {
		case 1: {
			

			cout << endl;
			system("pause");
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