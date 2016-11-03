#pragma once
#include "GameObject.h"
class Birds :
	public GameObject
{
public:
	Birds();
	virtual ~Birds();

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

public:
	float radius;
};

