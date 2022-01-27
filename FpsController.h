#pragma once
class FpsController
{
	int fps;
	float deltaTime;
	float lastStamp;
public:
	FpsController(int _fps);

	bool isNextFrame(int stamp);

	void setFps(int _fps);

	int getFps();
};

