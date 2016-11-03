#pragma once
#include "GameObject.h"
class FumeCloud :
	public GameObject
{
public:
	FumeCloud();
	virtual ~FumeCloud();

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

public:
	float radius;
};

