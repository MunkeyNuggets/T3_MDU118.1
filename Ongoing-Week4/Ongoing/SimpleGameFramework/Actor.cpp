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

//save child specific variable "health"
void Actor::SaveAsText_Internal(std::ostream& outputStream)
{
	outputStream << "," << health;
}

//load child specific variable "health"
void Actor::LoadFromText_Internal(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> health;
}

//access the render function
void Actor::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	//get image called "actor" and render to canvas at it's unique location
	ImageWrapper* actor = GameFrameworkInstance.GetLoadedImage("actor");
	GameFrameworkInstance.DrawImage(canvas, location, actor);
}
