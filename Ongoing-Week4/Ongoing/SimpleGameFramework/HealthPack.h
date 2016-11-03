#pragma once
#include "GameObject.h"
class HealthPack :
	public GameObject
{
public:
	HealthPack();
	virtual ~HealthPack();

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

public:
	float radius;
	int amount;
	bool destructible;
};

