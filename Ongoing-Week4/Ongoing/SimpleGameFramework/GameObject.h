#pragma once

#include <iostream>
#include <string>

enum GameObjectType {
	egotBase,
	egotActor,

	// ALL NEW TYPES GO ABOVE HERE
	egotNumTypes
};

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void SaveAsText(std::ostream& outputStream);
	virtual void LoadFromText(std::istream& inputStream);

protected:
	virtual void SaveAsText_Internal(std::ostream& outputStream);
	virtual void LoadFromText_Internal(std::istream& inputStream);

public:
	GameObjectType type;
	Vector2i location;
	std::string name;

	std::string imageName;
	float rotation;
	float xScale;
	float yScale;
};

