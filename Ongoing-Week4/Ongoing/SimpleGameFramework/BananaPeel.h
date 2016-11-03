#pragma once
#include "GameObject.h"
class BananaPeel :
	public GameObject
{
public:
	BananaPeel();
	virtual ~BananaPeel();

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

public:
	float radius;
};

