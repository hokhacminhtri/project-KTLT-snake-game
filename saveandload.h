#pragma once

#ifndef _SAVEANDLOAD_
#define _SAVEANDLOAD_

#include "parameter.h"

using namespace std;

int SaveGame(GAMEOBJECT* gameObject);
GAMEOBJECT* LoadGame(string saveFile);

#endif // !_SAVEANDLOAD_
