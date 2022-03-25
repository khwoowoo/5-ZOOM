#pragma once
class Time:public CSingleInstance<Time>
{
	DWORD tempFPS, FPS;
	DWORD CurrentTime, LastTime;
	DWORD TotalTime, DeltaTime;
public:
	float fDeltaTime;
public:
	Time();
	virtual ~Time();

	void Update();
};

