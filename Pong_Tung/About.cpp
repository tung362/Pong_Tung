#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Text aboutBackButton;
extern Text tungText;
extern Box selectBox;
extern int LevelID;
extern bool useLevelDelay;

bool keyIsPressedAbout = true;
float keyPressDelayTimerAbout = 0;

void About()
{
	if (keyIsPressedAbout == true)
	{
		keyPressDelayTimerAbout += getDeltaTime();

		if (keyPressDelayTimerAbout > 0.5f)
		{
			keyIsPressedAbout = false;
		}
	}

	if (getKey(32) && keyIsPressedAbout == false) //pressed space key
	{
		keyPressDelayTimerAbout = 0;
		useLevelDelay = true;
		keyIsPressedAbout = true;
		LevelID = 2;
	}
	selectBox = { { aboutBackButton.position.x + 40, aboutBackButton.position.y }, 60, 150 };

	DrawText(aboutBackButton.position, aboutBackButton.text, aboutBackButton.Height, aboutBackButton.Width);
	DrawText(tungText.position, tungText.text, tungText.Height, tungText.Width);
	DrawBox(selectBox.position, selectBox.height, selectBox.width);
}