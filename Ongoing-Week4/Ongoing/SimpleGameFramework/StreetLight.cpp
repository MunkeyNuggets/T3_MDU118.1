#include "stdafx.h"
#include "StreetLight.h"


StreetLight::StreetLight() : GameObject()
{
	type = egotStreetLight;
}


StreetLight::~StreetLight()
{
}

//save child specific variables "radius", "amount" and "destructible"
void StreetLight::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << width
		<< "," << height;
}

//load child specific variables "radius", "amount" and "destructible"
void StreetLight::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> width
		>> dummyChar >> height;
}

void StreetLight::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	//get image called "streetLight" and render to canvas at it's unique location
	ImageWrapper* streetLight = GameFrameworkInstance.GetLoadedImage("streetLight");
	GameFrameworkInstance.DrawImage(canvas, location, streetLight);
}