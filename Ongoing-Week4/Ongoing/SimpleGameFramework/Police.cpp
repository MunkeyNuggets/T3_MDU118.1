#include "stdafx.h"
#include "Police.h"


Police::Police() : GameObject()
{
	type = egotPolice;
}


Police::~Police()
{
}

void Police::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << radius;
}

void Police::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> radius;
}