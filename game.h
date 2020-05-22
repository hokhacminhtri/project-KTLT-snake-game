#pragma once
#include "parameter.h"
/***************Cac ham tao giao dien game***************/
void drawBoard(int x, int y, int width, int height);
void OpenGame();
void Loading();
void Menu();
void NewGame();
int Input(SNAKE* snake);
void Update(SNAKE* snake, POS& fruit,POS* gate, int& vt);
void Render(SNAKE* snake, POS& fruit);
