#pragma once
#include<windows.h>
#include<time.h>

struct TIMER {
	double currentTime;
	double prevTime;
	double deltaTime;
	double frameRate;
	bool timeStep();
};

