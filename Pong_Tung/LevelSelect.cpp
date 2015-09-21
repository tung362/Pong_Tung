#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Text levelSelectTitle;
extern Text Level1Text;
extern Text Level2Text;
extern Text Level3Text;
extern Text LSBackButton;
extern Box selectBox;
extern int LevelID;
extern int TempLevelID;

int LSselectID = 1; //1 = Level 1, 2 = Level 2, 3 = Level 3, 4 = Back
bool LSkeyIsPressed = false;
float LSkeyPressDelayTimer = 0;

bool LSuseLevelDelay = false;
float LSuseLevelDelayTimer = 0;

bool keyIsPressedLS = true;
float keyPressDelayTimerLS = 0;
extern bool useLevelDelay;

void LevelSelect()
{
	//How long until they can press the key again (Prevents Super fast button select)
	if (LSkeyIsPressed == true)
	{
		LSkeyPressDelayTimer += getDeltaTime();

		if (LSkeyPressDelayTimer > 0.2f)
		{
			LSkeyIsPressed = false;
		}
	}

	//How long until they can Transition levels agein (Prevents instant transition back)
	if (LSuseLevelDelay == true)
	{
		LSuseLevelDelayTimer += getDeltaTime();

		if (LSuseLevelDelayTimer > 1.5f)
		{
			LSuseLevelDelay = false;
		}
	}

	if (keyIsPressedLS == true)
	{
		keyPressDelayTimerLS += getDeltaTime();

		if (keyPressDelayTimerLS > 0.5f)
		{
			keyIsPressedLS = false;
		}
	}

	//Move select bar up
	if (getKey('w') && LSkeyIsPressed == false)
	{
		LSselectID -= 1;
		LSkeyPressDelayTimer = 0;
		LSkeyIsPressed = true;
	}
	//Move select bar down
	else if (getKey('s') && LSkeyIsPressed == false)
	{
		LSselectID += 1;
		LSkeyPressDelayTimer = 0;
		LSkeyIsPressed = true;
	}

	//Loops Select box to the bottom
	if (LSselectID <= 0)
	{
		LSselectID = 4;
	}
	//Loops Select box to the top
	else if (LSselectID > 4)
	{
		LSselectID = 1;
	}

	/////////
	if (LSselectID == 1) //Level 1
	{
		selectBox = { { Level1Text.position.x + 150, Level1Text.position.y }, 60, 370 };
		if (getKey(32) && LSuseLevelDelay == false && keyIsPressedLS == false)
		{
			TempLevelID = 7;
			LSuseLevelDelayTimer = 0;
			LSuseLevelDelay = true;
			LevelID = 6; //pressed space key
		}
	}
	else if (LSselectID == 2) //Level 2
	{
		selectBox = { { Level2Text.position.x + 150, Level2Text.position.y }, 60, 370 };
		if (getKey(32) && LSuseLevelDelay == false && keyIsPressedLS == false)
		{
			TempLevelID = 8;
			LSuseLevelDelayTimer = 0;
			LSuseLevelDelay = true;
			LevelID = 6;
		}
	}
	else if (LSselectID == 3) //Level 3
	{
		selectBox = { { Level3Text.position.x + 150, Level3Text.position.y }, 60, 370 };
		if (getKey(32) && LSuseLevelDelay == false && keyIsPressedLS == false)
		{
			TempLevelID = 9;
			LSuseLevelDelayTimer = 0;
			LSuseLevelDelay = true;
			LevelID = 6;
		}
	}
	else if (LSselectID == 4) //Back
	{
		selectBox = { { LSBackButton.position.x + 45, LSBackButton.position.y }, 60, 140 };
		if (getKey(32) && LSuseLevelDelay == false && keyIsPressedLS == false)
		{
			LSuseLevelDelayTimer = 0;
			LSuseLevelDelay = true;
			LevelID = 2;
		}
	}
	/////////

	DrawText(levelSelectTitle.position, levelSelectTitle.text, levelSelectTitle.Height, levelSelectTitle.Width);
	DrawText(Level1Text.position, Level1Text.text, Level1Text.Height, Level1Text.Width);
	DrawText(Level2Text.position, Level2Text.text, Level2Text.Height, Level2Text.Width);
	DrawText(Level3Text.position, Level3Text.text, Level3Text.Height, Level3Text.Width);
	DrawText(LSBackButton.position, LSBackButton.text, LSBackButton.Height, LSBackButton.Width);
	DrawBox(selectBox.position, selectBox.height, selectBox.width);
}