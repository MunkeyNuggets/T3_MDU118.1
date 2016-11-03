#pragma once
#include "GameObject.h"
class Car :
	public GameObject
{
public:
	Car();
	virtual ~Car();

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

public:
	float width;
	float height;
};

