#include "stdafx.h"
#include "HealthPack.h"


HealthPack::HealthPack() : GameObject()
{
	type = egotHealthPack;
}


HealthPack::~HealthPack()
{
}

//save child specific variables "radius", "amount" and "destructible"
void HealthPack::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << radius
		<< "," << amount
		<< "," << destructible;
}

//load child specific variables "radius", "amount" and "destructible"
void HealthPack::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> radius
		>> dummyChar >> amount
		>> dummyChar >> destructible;
}

void HealthPack::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	//get image called "healthPack" and render to canvas at it's unique location
	ImageWrapper* healthPack = GameFrameworkInstance.GetLoadedImage("healthPack");
	GameFrameworkInstance.DrawImage(canvas, location, healthPack);
}