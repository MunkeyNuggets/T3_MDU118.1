#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
	type = egotBase;
}


GameObject::~GameObject()
{
}

//void GameObject::SaveAsText_Internal(std::ostream& outputStream)
//{
//	// Save any child specific info
//	// If saving out info MUST ADD IN LEADING COMMA!
//	// DO NOT ADD END OF LINE CHARACTER HERE!
//}
//
//void GameObject::LoadFromText_Internal(std::istream& inputStream)
//{
//	// load any child specific info
//}

void GameObject::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawCircle(canvas, location, 50, true, 
									 Gdiplus::Color::AliceBlue);
}

void GameObject::SaveAsText(std::ostream& outputStream)
{
	outputStream	<< type			<< ","
					<< name			<< ","
					<< location.X	<< "," << location.Y	<< ","
					<< imageName	<< ","
					<< rotation		<< ","
					<< xScale		<< "," << yScale;

	SaveAsText_Internal(outputStream);

	outputStream	<< std::endl;
}

void GameObject::LoadFromText(std::istream& inputStream)
{
	char dummyValue;
	// consume/skip over the comma
	inputStream >> dummyValue;

	// read in up to the comma and store into name
	// throw away the trailing comma
	std::getline(inputStream, name, ',');

	// read in the location
	inputStream >> location.X;
	inputStream >> dummyValue;
	inputStream >> location.Y;

	inputStream >> dummyValue;

	// read in up to the comma and store into name
	// throw away the trailing comma
	std::getline(inputStream, imageName, ',');

	inputStream >> rotation;
	inputStream >> dummyValue;

	inputStream >> xScale;
	inputStream >> dummyValue;
	inputStream >> yScale;

	LoadFromText_Internal(inputStream);
}