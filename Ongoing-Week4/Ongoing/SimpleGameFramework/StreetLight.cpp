#include "stdafx.h"
#include "StreetLight.h"


StreetLight::StreetLight() : GameObject()
{
	type = egotStreetLight;
}


StreetLight::~StreetLight()
{
}

void StreetLight::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << width
		<< "," << height;
}

void StreetLight::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> width
		>> dummyChar >> height;
}