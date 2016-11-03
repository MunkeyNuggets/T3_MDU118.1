#include "stdafx.h"
#include "Car.h"


Car::Car() : GameObject()
{
	type = egotCar;
}


Car::~Car()
{
}

//save child specific variables "width" and "hight"
void Car::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << width
		<< "," << height;
}

//load child specific variables "width" and "hight"
void Car::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> width
		>> dummyChar >> height;
}

void Car::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	//get image called "car" and render to canvas at it's unique location
	ImageWrapper* car = GameFrameworkInstance.GetLoadedImage("car");
	GameFrameworkInstance.DrawImage(canvas, location, car);
}
