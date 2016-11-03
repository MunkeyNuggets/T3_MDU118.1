#include "stdafx.h"
#include "FumeCloud.h"


FumeCloud::FumeCloud() : GameObject()
{
	type = egotFumeCloud;
}


FumeCloud::~FumeCloud()
{
}

void FumeCloud::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << radius;
}

void FumeCloud::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> radius;
}