#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Text instructTitle;
extern Text instrucBackButton;
extern Text wKeyText;
extern Text sKeyText;
extern Box selectBox;
extern int LevelID;
extern bool useLevelDelay;

bool keyIsPressedInstruct = true;
float keyPressDelayTimerInstruct = 0;

void Instructions()
{
	if (keyIsPressedInstruct == true)
	{
		keyPressDelayTimerInstruct += getDeltaTime();

		if (keyPressDelayTimerInstruct > 0.5f)
		{
			keyIsPressedInstruct = false;
		}
	}

	if (getKey(32) && keyIsPressedInstruct == false) //pressed space key
	{
		keyPressDelayTimerInstruct = 0;
		useLevelDelay = true;
		keyIsPressedInstruct = true;
		LevelID = 2;
	}
	selectBox = { { instrucBackButton.position.x + 40, instrucBackButton.position.y }, 60, 150 };

	DrawText(instructTitle.position, instructTitle.text, instructTitle.Height, instructTitle.Width);
	DrawText(instrucBackButton.position, instrucBackButton.text, instrucBackButton.Height, instrucBackButton.Width);
	DrawText(wKeyText.position, wKeyText.text, wKeyText.Height, wKeyText.Width);
	DrawText(sKeyText.position, sKeyText.text, sKeyText.Height, sKeyText.Width);
	DrawBox(selectBox.position, selectBox.height, selectBox.width);
}