#pragma once
#include "GameObject.h"
class Police :
	public GameObject
{
public:
	Police();
	virtual ~Police();

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

public:
	float radius;
};

