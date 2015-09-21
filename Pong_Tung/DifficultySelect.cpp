#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Text difficultySelectTitle;
extern Text difEasy;
extern Text difNormal;
extern Text difHard;
extern Text DSBackButton;
extern Box selectBox;
extern int LevelID;
extern int TempLevelID;
extern int Difficulty;

int DSselectID = 1; //1 = Easy 1, 2 = Normal 2, 3 = Hard, 4 = Back
bool DSkeyIsPressed = false;
float DSkeyPressDelayTimer = 0;

bool DSuseLevelDelay = false;
float DSuseLevelDelayTimer = 0;

bool keyIsPressedDS = true;
float keyPressDelayTimerDS = 0;
extern bool LSuseLevelDelay;

void DifficultySelect()
{
	//How long until they can press the key again (Prevents Super fast button select)
	if (DSkeyIsPressed == true)
	{
		DSkeyPressDelayTimer += getDeltaTime();

		if (DSkeyPressDelayTimer > 0.2f)
		{
			DSkeyIsPressed = false;
		}
	}

	//How long until they can Transition levels agein (Prevents instant transition back)
	if (DSuseLevelDelay == true)
	{
		DSuseLevelDelayTimer += getDeltaTime();

		if (DSuseLevelDelayTimer > 1.5f)
		{
			DSuseLevelDelay = false;
		}
	}

	if (keyIsPressedDS == true)
	{
		keyPressDelayTimerDS += getDeltaTime();

		if (keyPressDelayTimerDS > 0.5f)
		{
			keyIsPressedDS = false;
		}
	}

	//Move select bar up
	if (getKey('w') && DSkeyIsPressed == false)
	{
		DSselectID -= 1;
		DSkeyPressDelayTimer = 0;
		DSkeyIsPressed = true;
	}
	//Move select bar down
	else if (getKey('s') && DSkeyIsPressed == false)
	{
		DSselectID += 1;
		DSkeyPressDelayTimer = 0;
		DSkeyIsPressed = true;
	}

	//Loops Select box to the bottom
	if (DSselectID <= 0)
	{
		DSselectID = 4;
	}
	//Loops Select box to the top
	else if (DSselectID > 4)
	{
		DSselectID = 1;
	}

	/////////
	if (DSselectID == 1) //Easy
	{
		selectBox = { { difEasy.position.x + 23, difEasy.position.y }, 60, 110 };
		if (getKey(32) && DSuseLevelDelay == false && keyIsPressedDS == false)
		{
			Difficulty = 1;
			DSuseLevelDelayTimer = 0;
			DSuseLevelDelay = true;
			LevelID = TempLevelID; //pressed space key
		}
	}
	else if (DSselectID == 2) //Normal
	{
		selectBox = { { difNormal.position.x + 33, difNormal.position.y }, 60, 130 };
		if (getKey(32) && DSuseLevelDelay == false && keyIsPressedDS == false)
		{
			Difficulty = 2;
			DSuseLevelDelayTimer = 0;
			DSuseLevelDelay = true;
			LevelID = TempLevelID;
		}
	}
	else if (DSselectID == 3) //Hard
	{
		selectBox = { { difHard.position.x + 23, difHard.position.y }, 60, 110 };
		if (getKey(32) && DSuseLevelDelay == false && keyIsPressedDS == false)
		{
			Difficulty = 3;
			DSuseLevelDelayTimer = 0;
			DSuseLevelDelay = true;
			LevelID = TempLevelID;
		}
	}
	else if (DSselectID == 4) //Back
	{
		selectBox = { { DSBackButton.position.x + 45, DSBackButton.position.y }, 60, 140 };
		if (getKey(32) && DSuseLevelDelay == false && keyIsPressedDS == false)
		{
			DSuseLevelDelayTimer = 0;
			DSuseLevelDelay = true;
			LevelID = 2;
		}
	}
	/////////

	DrawText(difficultySelectTitle.position, difficultySelectTitle.text, difficultySelectTitle.Height, difficultySelectTitle.Width);
	DrawText(difEasy.position, difEasy.text, difEasy.Height, difEasy.Width);
	DrawText(difNormal.position, difNormal.text, difNormal.Height, difNormal.Width);
	DrawText(difHard.position, difHard.text, difHard.Height, difHard.Width);
	DrawText(DSBackButton.position, DSBackButton.text, DSBackButton.Height, DSBackButton.Width);
	DrawBox(selectBox.position, selectBox.height, selectBox.width);
}