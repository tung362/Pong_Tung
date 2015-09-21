#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Brick L3brickss[35];
extern Brick L3Movingbrickss[4];

bool L3BrickRunOnce = true;
Vec2 L3MovingBrickMovement[4];

void Level3BrickMovement()
{
	//Assigning default values
	if (L3BrickRunOnce == true)
	{
		for (int x = 0; x < 4; ++x) L3MovingBrickMovement[x] = { 0, 0 };
		L3Movingbrickss[0] = { { 450, 400 }, 300, 1, 100, 30, true };
		L3Movingbrickss[1] = { { 400, 400 }, 300, 1, 100, 30, false };
		L3Movingbrickss[2] = { { 700, 400 }, 300, 1, 100, 30, true };
		L3Movingbrickss[3] = { { 750, 400 }, 300, 1, 100, 30, false };

		//First Col
		for (int x = 0; x < 7; ++x) L3brickss[x] = { { 530, 100 + (x * 100.0f) }, 600, 1, 100, 30 };
		//Second Col
		for (int x = 0; x < 7; ++x) L3brickss[7 + x] = { { 560, 100 + (x * 100.0f) }, 600, 1, 100, 30 };
		//Third Col
		for (int x = 0; x < 7; ++x) L3brickss[14 + x] = { { 590, 100 + (x * 100.0f) }, 600, 1, 100, 30 };
		//Fourth Col
		for (int x = 0; x < 7; ++x) L3brickss[28 + x] = { { 620, 100 + (x * 100.0f) }, 600, 1, 100, 30 };

		L3BrickRunOnce = false;
	}
	else
	{
		//Draw normal static bricks
		for (int x = 0; x < 35; ++x) DrawBox(L3brickss[x].position, L3brickss[x].height, L3brickss[x].width);

		//Applies movement and then draw moving bricks
		for (int x = 0; x < 4; ++x)
		{
			if (L3Movingbrickss[x].MoveUp == true && L3Movingbrickss[x].position.y > 0 + L3Movingbrickss[x].height / 2)
			{
				L3MovingBrickMovement[x].y = (1 * L3Movingbrickss[x].speed) * getDeltaTime();
			}
			else L3Movingbrickss[x].MoveUp = false;

			if (L3Movingbrickss[x].MoveUp == false && L3Movingbrickss[x].position.y < 800 - L3Movingbrickss[x].height / 2)
			{
				L3MovingBrickMovement[x].y = (-1 * L3Movingbrickss[x].speed) * getDeltaTime();
			}
			else L3Movingbrickss[x].MoveUp = true;

			L3Movingbrickss[x].position = { L3Movingbrickss[x].position.x - L3MovingBrickMovement[x].x,  L3Movingbrickss[x].position.y - L3MovingBrickMovement[x].y };
			DrawBox(L3Movingbrickss[x].position, L3Movingbrickss[x].height, L3Movingbrickss[x].width);
		}
	}
}