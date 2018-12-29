#include "DxLib.h"
class System {
public:
	void Loop(int startTime,int endTime) {
		ScreenFlip();
		ClearDrawScreen();
		WaitTimer(1000 / 60 - (endTime - startTime));
	}
	
};