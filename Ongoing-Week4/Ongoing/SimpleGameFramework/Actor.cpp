#include "stdafx.h"
#include "Actor.h"


Actor::Actor() :
	GameObject()
{
	type = egotActor;
}


Actor::~Actor()
{
}

void Actor::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << health;
}

void Actor::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> health;
}
