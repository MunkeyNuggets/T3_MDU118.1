#pragma once

#include <iostream>
#include <string>

enum GameObjectType {
	//create different class types
	egotBase,
	egotActor,
	egotCar,
	egotStreetLight,
	egotFireHydrant,
	egotBananaPeel,
	egotFumeCloud,
	egotHealthPack,
	egotEnergyBoost,
	egotBirds,
	egotPolice,

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
	virtual void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);

	bool operator == (const GameObject& rhs)
	{
		return (type == rhs.type) &&
			(location == rhs.location);
	}

	bool operator != (const GameObject& rhs)
	{
		return !(*this == rhs);
	}

protected:
	// virtual keyword + the = 0 makes these pure virtual function
	virtual void SaveAsText_Internal(std::ostream& outputStream) = 0;
	virtual void LoadFromText_Internal(std::istream& inputStream) = 0;

	//list commen variables between child classes
public:
	GameObjectType type;
	Vector2i location;
	std::string name;

	std::string imageName;
	float rotation;
	float xScale;
	float yScale;
};

