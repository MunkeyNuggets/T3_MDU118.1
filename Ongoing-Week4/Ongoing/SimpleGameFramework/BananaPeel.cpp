#include "stdafx.h"
#include "BananaPeel.h"


BananaPeel::BananaPeel() : GameObject()
{
	type = egotBananaPeel;
}


BananaPeel::~BananaPeel()
{
}

void BananaPeel::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << radius;
}

void BananaPeel::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> radius;
}
