#include "stdafx.h"
#include "Police.h"


Police::Police() : GameObject()
{
	type = egotPolice;
}


Police::~Police()
{
}

//save child specific variable "radius"
void Police::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << radius;
}

//load child specific variable "radius"
void Police::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> radius;
}

void Police::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	//get image called "police" and render to canvas at it's unique location
	ImageWrapper* police = GameFrameworkInstance.GetLoadedImage("police");
	GameFrameworkInstance.DrawImage(canvas, location, police);
}