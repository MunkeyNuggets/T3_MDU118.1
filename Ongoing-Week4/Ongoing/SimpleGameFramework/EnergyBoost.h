#pragma once
#include "GameObject.h"
class EnergyBoost :
	public GameObject
{
public:
	EnergyBoost();
	virtual ~EnergyBoost();

protected:
	//setup inputStream and outputStream for this class
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);
	virtual void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);

	//list class specific variables
public:
	float radius;
	int amount;
	bool destructible;
};

