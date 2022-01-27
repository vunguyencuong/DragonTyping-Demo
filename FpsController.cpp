#include "FpsController.h"

	FpsController::FpsController(int _fps)
	{
		fps = _fps;
		deltaTime = 1000.f / fps; // so giay cua 1 khung hinh
		lastStamp = 0.f; // moc tgian cua currentFrame
	}

	bool FpsController::isNextFrame(int stamp)
{
	if (stamp - lastStamp > deltaTime) // stamp - moc tgian muon kiem tra 
	{
		lastStamp = stamp;
		return true;
	}
	else
	{
		return false;
	}
}

	void FpsController::setFps(int _fps)
	{
		fps = _fps;
		deltaTime = 1000.f / fps;
	}

	int FpsController::getFps()
	{
		return fps;
	}
