#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Text title;
extern int LevelID;

float splashTimer = 0;
bool runOnceSplash = true;
float previousDeltaTime; //Used for the ball since deltatime changes later on

void SplashScreen()
{
	if (runOnceSplash == true)
	{
		previousDeltaTime = getDeltaTime();
		runOnceSplash = false;
	}

	splashTimer += getDeltaTime();

	//Change to main menu after 4 seconds
	if (splashTimer > 4)
	{
		LevelID = 2;
		splashTimer = 0;
	}
	DrawText(title.position, title.text, title.Height, title.Width);
}