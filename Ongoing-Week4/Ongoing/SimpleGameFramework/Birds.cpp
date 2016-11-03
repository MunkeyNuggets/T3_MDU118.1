#include "stdafx.h"
#include "Birds.h"


Birds::Birds() : GameObject()
{
	type = egotBirds;
}


Birds::~Birds()
{
}

//save child specific variable "radius"
void Birds::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << radius;
}

//load child specific variable "radius"
void Birds::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> radius;
}

void Birds::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	//get image called "birds" and render to canvas at it's unique location
	ImageWrapper* birds = GameFrameworkInstance.GetLoadedImage("birds");
	GameFrameworkInstance.DrawImage(canvas, location, birds);
}