#pragma once
#include "GameObject.h"
class StreetLight :
	public GameObject
{
public:
	StreetLight();
	virtual ~StreetLight();

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

public:
	float width;
	float height;
};

