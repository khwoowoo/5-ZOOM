#include "stdafx.h"


Time::Time()
{
	CurrentTime = timeGetTime();

	tempFPS = 0;
	FPS = 0;

	TotalTime = 0;
	DeltaTime = 0;

	fDeltaTime = 0.f;

	LastTime = CurrentTime;
}


Time::~Time()
{
}

void Time::Update()
{
	CurrentTime = timeGetTime();

	DeltaTime = CurrentTime - LastTime;
	fDeltaTime = DeltaTime / 1000.f;

	TotalTime += DeltaTime;
	++tempFPS;
	if (TotalTime >= 1000)
	{
		FPS = tempFPS;
		tempFPS = 0;
		TotalTime -= 1000;
	}
	LastTime = CurrentTime;
}
