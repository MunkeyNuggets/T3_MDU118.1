#include "stdafx.h"
#include "EnergyBoost.h"


EnergyBoost::EnergyBoost() : GameObject()
{
	type = egotEnergyBoost;
}


EnergyBoost::~EnergyBoost()
{
}

//save child specific variables "radius", "amount" and "destructible"
void EnergyBoost::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << radius
		<< "," << amount 
		<< "," << destructible;
}

//load child specific variables "radius", "amount" and "destructible"
void EnergyBoost::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> radius
		>> dummyChar >> amount
		>> dummyChar >> destructible;
}

void EnergyBoost::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	//get image called "energyBoost" and render to canvas at it's unique location
	ImageWrapper* energyBoost = GameFrameworkInstance.GetLoadedImage("energyBoost");
	GameFrameworkInstance.DrawImage(canvas, location, energyBoost);
}

