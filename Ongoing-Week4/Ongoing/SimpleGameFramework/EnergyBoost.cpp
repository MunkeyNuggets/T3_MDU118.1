#include "stdafx.h"
#include "EnergyBoost.h"


EnergyBoost::EnergyBoost() : GameObject()
{
	type = egotEnergyBoost;
}


EnergyBoost::~EnergyBoost()
{
}

void EnergyBoost::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << radius
		<< "," << amount 
		<< "," << destructible;
}

void EnergyBoost::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> radius
		>> dummyChar >> amount
		>> dummyChar >> destructible;
}
