#include "stdafx.h"
#include "Birds.h"


Birds::Birds() : GameObject()
{
	type = egotBirds;
}


Birds::~Birds()
{
}

void Birds::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << radius;
}

void Birds::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> radius;
}
