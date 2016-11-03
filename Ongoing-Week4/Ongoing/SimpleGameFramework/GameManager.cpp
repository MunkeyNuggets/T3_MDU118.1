#include "stdafx.h"
#include "GameManager.h"
#include <fstream>
#include <algorithm>
#include "Actor.h"
#include "BananaPeel.h"
#include "Birds.h"
#include "Car.h"
#include "EnergyBoost.h"
#include "FireHydrant.h"
#include "FumeCloud.h"
#include "HealthPack.h"
#include "Police.h"
#include "StreetLight.h"
#include <map>

GameManager& GameManager::Instance()
{
	static GameManager instance;

	return instance;
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

const char* Image1 = "Image1";

void GameManager::BeginPlay()
{
	////////////////////////////////////////////////////////////////////////////////
	// Begin example code

	std::map<std::string, int> stringIntMap;
	stringIntMap["zdfasdf"] = 5;

	int value = stringIntMap["zdfasdf"];

	// check if the value is NOT in the map
	if (stringIntMap.find("asdfsdafsdfsdf") == stringIntMap.end())
	{

	}

	// Load the image file Untitled.png from the Images folder. Give it the unique name of Image1
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/Untitled.png"), Image1);
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/Untitled2.png"), "A");

	Actor* object1 = new Actor();
	object1->location = Vector2i(50, 100);
	object1->name = "Object1";
	object1->rotation = 1.0f;
	object1->xScale = 2.0f;
	object1->yScale = 3.0f;
	object1->imageName = "Image1";
	object1->health = 100;

	BananaPeel* object2 = new BananaPeel();
	object2->location = Vector2i(100, 500);
	object2->name = "BananaPeel";
	object2->rotation = 1.0f;
	object2->xScale = 1.0f;
	object2->yScale = 1.0f;
	object2->imageName = "bananaPeel";
	object2->radius = 5.0f;

	Birds* object3 = new Birds();
	object3->location = Vector2i(30, 50);
	object3->name = "Birds";
	object3->rotation = 1.0f;
	object3->xScale = 1.0f;
	object3->yScale = 1.0f;
	object3->imageName = "birds";
	object3->radius = 5.0f;
	
	Car* object4 = new Car();
	object4->location = Vector2i(300, 100);
	object4->name = "Car";
	object4->rotation = 1.0f;
	object4->xScale = 1.0f;
	object4->yScale = 1.0f;
	object4->imageName = "car";
	object4->width = 1.0f;
	object4->height = 1.0f;

	EnergyBoost* object5 = new EnergyBoost();
	object5->location = Vector2i(20, 100);
	object5->name = "EnergyBoost";
	object5->rotation = 1.0f;
	object5->xScale = 1.0f;
	object5->yScale = 1.0f;
	object5->imageName = "energyBoost";
	object5->radius = 5.0f;
	object5->amount = 3;
	object5->destructible = true;

	FireHydrant* object6 = new FireHydrant();
	object6->location = Vector2i(100, 100);
	object6->name = "FireHydrant";
	object6->rotation = 1.0f;
	object6->xScale = 1.0f;
	object6->yScale = 1.0f;
	object6->imageName = "fireHydrant";
	object6->width = 1.0f;
	object6->height = 1.0f;

	FumeCloud* object7 = new FumeCloud();
	object7->location = Vector2i(50, 100);
	object7->name = "FumeCloud";
	object7->rotation = 1.0f;
	object7->xScale = 1.0f;
	object7->yScale = 1.0f;
	object7->imageName = "fumeCloud";
	object7->radius = 5.0f;
	
	HealthPack* object8 = new HealthPack();
	object8->location = Vector2i(500, 500);
	object8->name = "HealthPack";
	object8->rotation = 1.0f;
	object8->xScale = 10.0f;
	object8->yScale = 1.0f;
	object8->imageName = "healthPack";
	object8->radius = 5.0f;
	object8->amount = 3;
	object8->destructible = true;

	Police* object9 = new Police();
	object9->location = Vector2i(50, 250);
	object9->name = "Police";
	object9->rotation = 1.0f;
	object9->xScale = 1.0f;
	object9->yScale = 1.0f;
	object9->imageName = "police";
	object9->radius = 5.0f;

	StreetLight* object10 = new StreetLight();
	object10->location = Vector2i(100, 250);
	object10->name = "StreetLight";
	object10->rotation = 1.0f;
	object10->xScale = 1.0f;
	object10->yScale = 1.0f;
	object10->imageName = "streetLight";
	object10->width = 1.0f;
	object10->height = 1.0f;

	std::ofstream outputFile("objects.csv");
	outputFile << 1 << std::endl;	// version number
	outputFile << 10 << std::endl;	// number of objects in file
	object1->SaveAsText(outputFile);
	object2->SaveAsText(outputFile);
	object3->SaveAsText(outputFile);
	object4->SaveAsText(outputFile);
	object5->SaveAsText(outputFile);
	object6->SaveAsText(outputFile);
	object7->SaveAsText(outputFile);
	object8->SaveAsText(outputFile);
	object9->SaveAsText(outputFile);
	object10->SaveAsText(outputFile);
	
	outputFile.close();

	delete object1;
	delete object2;
	delete object3;
	delete object4;
	delete object5;
	delete object6;
	delete object7;
	delete object8;
	delete object9;
	delete object10;

	std::ifstream inputFile("objects.csv");
	int versionNumber = 0;
	int numObjects = 0;
	inputFile >> versionNumber;
	inputFile >> numObjects;

	// load all of the objects
	objects.reserve(numObjects);
	for (int index = 0; index < numObjects; ++index)
	{
		// read the enumeration into a integer then cast/convert it to the enum
		int typeValue;
		inputFile >> typeValue;
		GameObjectType type = (GameObjectType)typeValue;

		GameObject* loadedObjectPtr = nullptr;
		switch (type)
		{
		case egotBase:
			DebugLog("Object has base type. Something is very bad!");
			break;

		case egotActor:
			loadedObjectPtr = new Actor();
			break;

		case egotBananaPeel:
			loadedObjectPtr = new BananaPeel();
			break;

		case egotBirds:
			loadedObjectPtr = new Birds();
			break;

		case egotCar:
			loadedObjectPtr = new Car();
			break;

		case egotEnergyBoost:
			loadedObjectPtr = new EnergyBoost();
			break;

		case egotFireHydrant:
			loadedObjectPtr = new FireHydrant();
			break;

		case egotFumeCloud:
			loadedObjectPtr = new FumeCloud();
			break;

		case egotHealthPack:
			loadedObjectPtr = new HealthPack();
			break;

		case egotPolice:
			loadedObjectPtr = new Police();
			break;

		case egotStreetLight:
			loadedObjectPtr = new StreetLight();
			break;
		}
		
		loadedObjectPtr->LoadFromText(inputFile);

		objects.push_back(loadedObjectPtr);
	}

	Actor* actor1 = new Actor();
	Actor* actor2 = new Actor();

	// By checking pointers like this I'm saying
	// is actor1 referring to the same thing as actor2
	if (actor1 == actor2)
	{

	}

	// Do actor1 and actor2 have the same information stored
	// ie. are they clones?
	if (*actor1 == *actor2)
	{

	}

	delete actor1;
	delete actor2;

//	std::sort(objects.begin(), objects.end());

	DebugLog("-----");


	// Static Cast - used for very simple cases
	{
		int intValue = static_cast<int>(1.2f);
	}

	// Dynamic Cast - used with inheritance/polymorphism
	{
		GameObject* objectPtr = new Actor();

		// Is the objectPtr an Actor
		Actor* actorPtr = dynamic_cast<Actor*>(objectPtr);
		if (actorPtr)
		{
			// yes it's an actor
		}
		else
		{
			// it's something other than actor
		}
	}

	// Reinterpret Cast - low level input/output
	{
		// this is a very unsafe example
		std::string stringValue = "fred";
		int* intPtr = reinterpret_cast<int*>(&stringValue);
	}

	// C Style cast - only use for very very simple conversions
	{
		// this is safe code to use
		int intValue = (int)1.2f;

		// this code below is very unsafe!
		std::string stringValue = "fred";
		int* intPtr = (int*)(&stringValue);
	}

	// End example code
	////////////////////////////////////////////////////////////////////////////////
}

void GameManager::EndPlay()
{
	// iterate over all of the game objects in the list
	std::vector<GameObject*>::iterator objectIt;
	for (objectIt = objects.begin(); objectIt != objects.end(); ++objectIt)
	{
		GameObject* objectPtr = *objectIt;
		delete objectPtr;
	}

	// clear the vector (empty the elements)
	objects.clear();
}

void GameManager::Update(double deltaTime)
{

}

void GameManager::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	////////////////////////////////////////////////////////////////////////////////
	// Begin example code

	// Save the current transformation of the scene
	Gdiplus::Matrix transform;
	canvas.GetTransform(&transform);

	canvas.ScaleTransform(0.5f, 0.5f);
	canvas.RotateTransform(30.0f);
	canvas.TranslateTransform(200.0f, 200.0f);

	// tell all of the game objects to render
	for (GameObject* objectPtr : objects)
	{
		objectPtr->Render(canvas, clientRect);
	}

	/*//Render method demonstration (You can remove all of this code)
	GameFrameworkInstance.DrawLine(canvas, Vector2i(200, 200), Vector2i(400, 200), Gdiplus::Color::Red);

	GameFrameworkInstance.DrawRectangle(canvas, AABBi(Vector2i(10, 110), Vector2i(100, 200)), false, Gdiplus::Color::White);
	GameFrameworkInstance.DrawRectangle(canvas, AABBi(Vector2i(200, 110), Vector2i(300, 200)), true, Gdiplus::Color::White);

	canvas.SetTransform(&transform);

	GameFrameworkInstance.DrawCircle(canvas, Vector2i(200, 200), 50, false, Gdiplus::Color::White);
	GameFrameworkInstance.DrawCircle(canvas, Vector2i(400, 200), 50, true, Gdiplus::Color::White);

	GameFrameworkInstance.DrawText(canvas, Vector2i(10, 300), 12, "Arial", "Hello World!", Gdiplus::Color::White);

	// Load the image file Untitled.png from the Images folder. Give it the unique name of Image1
	ImageWrapper* image1 = GameFrameworkInstance.GetLoadedImage("A");
	GameFrameworkInstance.DrawImage(canvas, Vector2i(400, 400), image1);

	// Restore the transformation of the scene
	canvas.SetTransform(&transform);

	 End example code
	////////////////////////////////////////////////////////////////////////////////
	*/
	}
