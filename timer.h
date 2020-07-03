#pragma once

#ifndef _TIMER_
#define _TIMER_

#include<windows.h>
#include<time.h>

struct TIMER {
	double currentTime;
	double prevTime;
	double deltaTime;
	double frameRate;
	bool timeStep();
};

#endif // !_TIMER_


