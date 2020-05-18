#include "timer.h"

bool TIMER::timeStep() {
	prevTime = currentTime;
	currentTime = clock();
	deltaTime += float(currentTime - prevTime) / CLOCKS_PER_SEC;
	if (deltaTime >= frameRate) {
		while (deltaTime >= frameRate)
			deltaTime -= frameRate;
		return 1;
	}
	return 0;
}

