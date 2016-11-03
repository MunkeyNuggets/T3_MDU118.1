#include "stdafx.h"
#include "FireHydrant.h"


FireHydrant::FireHydrant() : GameObject()
{
	type = egotFireHydrant;
}


FireHydrant::~FireHydrant()
{
}

void FireHydrant::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << width
		<< "," << height;

}

void FireHydrant::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> width
		>> dummyChar >> height;
}