#pragma once
#include "GameObject.h"
class Actor :
	public GameObject
{
public:
	Actor();
	virtual ~Actor();

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

public:
	int health;
};

