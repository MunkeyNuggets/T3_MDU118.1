#include "stdafx.h"
#include "Car.h"


Car::Car() : GameObject()
{
	type = egotCar;
}


Car::~Car()
{
}

void Car::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << width
		<< "," << height;
}

void Car::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> width
		>> dummyChar >> height;
}
