#include "stdafx.h"
#include "HealthPack.h"


HealthPack::HealthPack() : GameObject()
{
	type = egotHealthPack;
}


HealthPack::~HealthPack()
{
}

void HealthPack::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << radius
		<< "," << amount
		<< "," << destructible;
}

void HealthPack::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> radius
		>> dummyChar >> amount
		>> dummyChar >> destructible;
}
