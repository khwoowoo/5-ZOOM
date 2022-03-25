#include "stdafx.h"


Math::Math()
{
}


Math::~Math()
{
}

float Math::lerp(int start, int end, int time)
{
	return start - time * (end - start);
}
