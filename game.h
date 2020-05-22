#pragma once
#include "parameter.h"
/***************Cac ham tao giao dien game***************/
void OpenGame();
void Loading();
void Menu();
void NewGame();
int Input(SNAKE* snake);
void Update(SNAKE* snake, POS& fruit, int& vt);
void Render(SNAKE* snake, POS& fruit);
