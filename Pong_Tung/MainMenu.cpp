#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Text mainTitle;
extern Text playButton;
extern Text instructionButton;
extern Text aboutButton;
extern Text exitButton;
extern Box selectBox;
extern int LevelID;

int selectID = 1; //1 = Play, 2 = Instructions, 3 = About, 4 = Exit
bool keyIsPressed = false;
float keyPressDelayTimer = 0;

bool useLevelDelay = false;
float useLevelDelayTimer = 0;

void MainMenu()
{
	//How long until they can press the key again (Prevents Super fast button select)
	if (keyIsPressed == true)
	{
		keyPressDelayTimer += getDeltaTime();

		if (keyPressDelayTimer > 0.2f)
		{
			keyIsPressed = false;
		}
	}

	//How long until they can Transition levels agein (Prevents instant transition back)
	if (useLevelDelay == true)
	{
		useLevelDelayTimer += getDeltaTime();

		if (useLevelDelayTimer > 1.5f)
		{
			useLevelDelay = false;
		}
	}

	//Move select bar up
	if (getKey('w') && keyIsPressed == false)
	{
		selectID -= 1;
		keyPressDelayTimer = 0;
		keyIsPressed = true;
	}
	//Move select bar down
	else if (getKey('s') && keyIsPressed == false)
	{
		selectID += 1;
		keyPressDelayTimer = 0;
		keyIsPressed = true;
	}

	//Loops Select box to the bottom
	if (selectID <= 0)
	{
		selectID = 4;
	}
	//Loops Select box to the top
	else if (selectID > 4)
	{
		selectID = 1;
	}

	if (selectID == 1) //Play
	{
		selectBox = { { playButton.position.x + 40, playButton.position.y }, 60, 150 };
		if (getKey(32) && useLevelDelay == false)
		{
			useLevelDelayTimer = 0;
			useLevelDelay = true;
			LevelID = 5; //pressed space key
		}
	}
	else if (selectID == 2) //Instruction
	{
		selectBox = { { instructionButton.position.x + 160, instructionButton.position.y }, 60, 390 };
		if (getKey(32) && useLevelDelay == false)
		{
			useLevelDelayTimer = 0;
			useLevelDelay = true;
			LevelID = 3;
		}
	}
	else if (selectID == 3) //About
	{
		selectBox = { { aboutButton.position.x + 55, aboutButton.position.y }, 60, 175 };
		if (getKey(32) && useLevelDelay == false)
		{
			useLevelDelayTimer = 0;
			useLevelDelay = true;
			LevelID = 4;
		}
	}
	else if (selectID == 4) //Exit
	{
		selectBox = { { exitButton.position.x + 40, exitButton.position.y }, 60, 150 };
		if (getKey(32) && useLevelDelay == false)
		{
			useLevelDelayTimer = 0;
			useLevelDelay = true;
			LevelID = 0;
		}
	}

	DrawText(mainTitle.position, mainTitle.text, mainTitle.Height, mainTitle.Width);
	DrawText(playButton.position, playButton.text, playButton.Height, playButton.Width);
	DrawText(instructionButton.position, instructionButton.text, instructionButton.Height, instructionButton.Width);
	DrawText(aboutButton.position, aboutButton.text, aboutButton.Height, aboutButton.Width);
	DrawText(exitButton.position, exitButton.text, exitButton.Height, exitButton.Width);
	DrawBox(selectBox.position, selectBox.height, selectBox.width);
}