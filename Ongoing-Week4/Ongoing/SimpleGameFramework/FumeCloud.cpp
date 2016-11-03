#include "stdafx.h"
#include "FumeCloud.h"


FumeCloud::FumeCloud() : GameObject()
{
	type = egotFumeCloud;
}


FumeCloud::~FumeCloud()
{
}

//save child specific variable "radius"
void FumeCloud::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << radius;
}

//load child specific variable "radius"
void FumeCloud::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> radius;
}

void FumeCloud::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	//get image called "fumeCloud" and render to canvas at it's unique location
	ImageWrapper* fumeCloud = GameFrameworkInstance.GetLoadedImage("fumeCloud");
	GameFrameworkInstance.DrawImage(canvas, location, fumeCloud);
}