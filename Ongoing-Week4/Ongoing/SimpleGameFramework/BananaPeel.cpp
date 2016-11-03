#include "stdafx.h"
#include "BananaPeel.h"


BananaPeel::BananaPeel() : GameObject()
{
	type = egotBananaPeel;

}


BananaPeel::~BananaPeel()
{
}

//save child specific variable "radius"
void BananaPeel::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << radius;
}

//load child specific variable "radius"
void BananaPeel::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> radius;
}

void BananaPeel::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	//get image called "bananaPeel" and render to canvas at it's unique location
	ImageWrapper* bananaPeel = GameFrameworkInstance.GetLoadedImage("bananaPeel");
	GameFrameworkInstance.DrawImage(canvas, location, bananaPeel);
}

