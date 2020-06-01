#pragma once
#include "parameter.h"

using namespace std;

int SaveGame(SNAKE* snake);

SNAKE* LoadGame(string saveFile);