#pragma once

#ifndef _SNAKE_
#define _SNAKE_

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<thread>
#include<stdlib.h>
#include<conio.h>
#include <iostream>
using namespace std;

void FixConsoleWindow();
void GotoXY(int x, int y);
void TextColor(int color);

/***************Cac ham tao giao dien game***************/
void Loading();
void Menu();

#endif // !_SNAKE_

