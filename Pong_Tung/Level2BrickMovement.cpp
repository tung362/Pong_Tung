#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Brick L2brickss[14];

bool L2BrickRunOnce = true;

void Level2BrickMovement()
{
	//Vec2 L2BrickMovement[14];

	//Assigning default values
	if (L2BrickRunOnce == true)
	{
		//for (int x = 0; x < 7; ++x) L2BrickMovement[x] = { 0, 0 };
		
		//First Half
		for (int x = 0; x < 7; ++x)
		{
			L2brickss[x] = { { 600, 100 + (x * 100.0f) }, 600, 1, 100, 30 };
		}
		//Second Half
		for (int x = 0; x < 7; ++x)
		{
			L2brickss[7 + x] = {  { 650, 100 + (x * 100.0f) }, 600, 1, 100, 30 };
		}

		L2BrickRunOnce = false;
	}
	else
	{
		for (int x = 0; x < 14; ++x)
		{
			//L2brickss[x].position = { L2brickss[x].position.x - L2BrickMovement[x].x,  L2brickss[x].position.y - L2BrickMovement[x].y };
			DrawBox(L2brickss[x].position, L2brickss[x].height, L2brickss[x].width);
		}
	}
}