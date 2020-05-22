#pragma once
#include "parameter.h"
/***************Cac ham tao giao dien game***************/
void OpenGame();
void Loading();
void Menu();
void NewGame();
int Input(SNAKE* snake);
void Update(SNAKE* snake, POS& fruit,int& vt);
void Render(SNAKE* snake, POS& fruit);
//ham kiem tra vt fruit co trung voi snake
bool IsValid(SNAKE* snake, int x, int y);
void GenerateFruit(SNAKE* snake, POS& fruit,int &vt);
