#pragma once
#include "GameObject.h"
class EnergyBoost :
	public GameObject
{
public:
	EnergyBoost();
	virtual ~EnergyBoost();

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

public:
	float radius;
	int amount;
	bool destructible;
};

