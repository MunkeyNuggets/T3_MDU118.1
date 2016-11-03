#include "stdafx.h"
#include "FireHydrant.h"


FireHydrant::FireHydrant() : GameObject()
{
	type = egotFireHydrant;
}


FireHydrant::~FireHydrant()
{
}

//save child specific variables "width" and "hight"
void FireHydrant::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << width
		<< "," << height;

}

//load child specific variables "width" and "hight"
void FireHydrant::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> width
		>> dummyChar >> height;
}

void FireHydrant::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	//get image called "fireHydrant" and render to canvas at it's unique location
	ImageWrapper* fireHydrant = GameFrameworkInstance.GetLoadedImage("fireHydrant");
	GameFrameworkInstance.DrawImage(canvas, location, fireHydrant);
}