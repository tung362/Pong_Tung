#include <iostream>
#include <cstring>
#include <ctime>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Ball ball;
extern Paddle player1;
extern Paddle player2;
extern float previousDeltaTime;
extern Brick L2brickss[8];
extern Brick L3brickss[35];
extern Brick L3Movingbrickss[4];
extern int LevelID;

bool runOnce = true;
bool setStartingPos = true;
float outOfEdgetimer = 0;

int Ball1()
{
	srand(time(NULL));

	//Ball's starting direction of movement
	if (runOnce == true)
	{
		if (rand() % 2 == 0) ball.direction = { -1 * (-1 * ball.speed) * previousDeltaTime , 1 * (-1 * ball.speed) * previousDeltaTime };
		else ball.direction = { 1 * (-1 * ball.speed) * previousDeltaTime , 1 * (-1 * ball.speed) * previousDeltaTime };
		//previousDeltaTime = getDeltaTime();
		runOnce = false;
	}

	//Starting Positions for differnt levels
	if (setStartingPos == true)
	{
		if (LevelID == 7) ball.position = { 600, 400 }; //Level 1
		else if (LevelID == 8) ball.position = { 500, 400 }; //Level 2
		else if (LevelID == 9) ball.position = { 430, 400 }; //Level 3
		setStartingPos = false;
	}

	//Reset the speed
	if (ball.position.x < 0 - 300 || ball.position.x > 1200 + 300)
	{
		outOfEdgetimer += getDeltaTime();
		if (outOfEdgetimer > 3.5)
		{
			if (rand() % 2 == 0) ball.direction = { -1 * (-1 * ball.speed) * previousDeltaTime , 1 * (-1 * ball.speed) * previousDeltaTime };
			else ball.direction = { 1 * (-1 * ball.speed) * previousDeltaTime , 1 * (-1 * ball.speed) * previousDeltaTime };
			outOfEdgetimer = 0;
		}
	}
	else
	{
		outOfEdgetimer = 0;
	}

	//Collisions//
	//////////////
	//When it hits a wall, reflect
	if (ball.position.y < 20 || ball.position.y > 780)
	{
		ball.direction.y = -ball.direction.y;
	}
	//if (ball.position.x < 20 || ball.position.x > 1180) ball.direction.x = -ball.direction.x;

	//When it hits the player1 paddle, reflect
	if (ball.position.x - 10 <= player1.position.x + player1.width / 2  //right side
		&& ball.position.x + 10 >= player1.position.x - player1.width / 2 //left side
		&& ball.position.y >= player1.position.y - player1.height / 2 //top portion of left side side
		&& ball.position.y <= player1.position.y + player1.height / 2) //bottom portion of left right side
	{
		if (ball.position.y + 10 <= player1.position.y + player1.height / 2  //top side
			&& ball.position.y + 10 >= player1.position.y - player1.height / 2 //bottom side
			&& ball.position.x <= player1.position.x + player1.width / 2 - 0.3f //right
			&& ball.position.x >= player1.position.x - player1.width / 2 + 0.3f) //left
		{
			ball.direction.y = -ball.direction.y * 1.05f;
		}

		ball.direction.x = -ball.direction.x * 1.05f;
	}

	//When it hits the player2 paddle, reflect
	if (ball.position.x - 10 <= player2.position.x + player2.width / 2 
		&& ball.position.x + 10 >= player2.position.x - player2.width / 2 
		&& ball.position.y >= player2.position.y - player2.height / 2 
		&& ball.position.y <= player2.position.y + player2.height / 2)
	{
		if (ball.position.y + 10 <= player2.position.y + player2.height / 2
			&& ball.position.y + 10 >= player2.position.y - player2.height / 2
			&& ball.position.x <= player2.position.x + player2.width / 2 - 0.3f
			&& ball.position.x >= player2.position.x - player2.width / 2 + 0.3f)
		{
			ball.direction.y = -ball.direction.y * 1.05f;
		}

		ball.direction.x = -ball.direction.x * 1.05f;
	}

	//When it hits the bricks from level 2, reflect
	if (LevelID == 8)
	{
		for (int x = 0; x < 14; ++x)
		{
			if (ball.position.x - 10 <= L2brickss[x].position.x + L2brickss[x].width / 2
				&& ball.position.x + 10 >= L2brickss[x].position.x - L2brickss[x].width / 2
				&& ball.position.y >= L2brickss[x].position.y - L2brickss[x].height / 2
				&& ball.position.y <= L2brickss[x].position.y + L2brickss[x].height / 2)
			{
				if (ball.position.y + 10 <= L2brickss[x].position.y + L2brickss[x].height / 2
					&& ball.position.y + 10 >= L2brickss[x].position.y - L2brickss[x].height / 2
					&& ball.position.x <= L2brickss[x].position.x + L2brickss[x].width / 2 - 0.3f
					&& ball.position.x >= L2brickss[x].position.x - L2brickss[x].width / 2 + 0.3f)
				{
					ball.direction.y = -ball.direction.y;
				}

				ball.direction.x = -ball.direction.x;
				L2brickss[x].position.x = 9000;
			}
		}
	}
	//When it hits the bricks from level 3, reflect
	else if (LevelID == 9)
	{
		for (int x = 0; x < 35; ++x)
		{
			if (ball.position.x - 10 <= L3brickss[x].position.x + L3brickss[x].width / 2
				&& ball.position.x + 10 >= L3brickss[x].position.x - L3brickss[x].width / 2
				&& ball.position.y >= L3brickss[x].position.y - L3brickss[x].height / 2
				&& ball.position.y <= L3brickss[x].position.y + L3brickss[x].height / 2)
			{
				if (ball.position.y + 10 <= L3brickss[x].position.y + L3brickss[x].height / 2
					&& ball.position.y + 10 >= L3brickss[x].position.y - L3brickss[x].height / 2
					&& ball.position.x <= L3brickss[x].position.x + L3brickss[x].width / 2 - 0.3f
					&& ball.position.x >= L3brickss[x].position.x - L3brickss[x].width / 2 + 0.3f)
				{
					ball.direction.y = -ball.direction.y;
				}

				ball.direction.x = -ball.direction.x;
				L3brickss[x].position.x = 9000;
			}
		}

		for (int x = 0; x < 4; ++x)
		{
			if (ball.position.x - 10 <= L3Movingbrickss[x].position.x + L3Movingbrickss[x].width / 2
				&& ball.position.x + 10 >= L3Movingbrickss[x].position.x - L3Movingbrickss[x].width / 2
				&& ball.position.y >= L3Movingbrickss[x].position.y - L3Movingbrickss[x].height / 2
				&& ball.position.y <= L3Movingbrickss[x].position.y + L3Movingbrickss[x].height / 2)
			{
				if (ball.position.y + 10 <= L3Movingbrickss[x].position.y + L3Movingbrickss[x].height / 2
					&& ball.position.y + 10 >= L3Movingbrickss[x].position.y - L3Movingbrickss[x].height / 2
					&& ball.position.x <= L3Movingbrickss[x].position.x + L3Movingbrickss[x].width / 2 - 0.3f
					&& ball.position.x >= L3Movingbrickss[x].position.x - L3Movingbrickss[x].width / 2 + 0.3f)
				{
					ball.direction.y = -ball.direction.y;
				}

				ball.direction.x = -ball.direction.x;
				L3Movingbrickss[x].position.x = 9000;
			}
		}
	}
	//////////////

	//Draw//
	ball.position = { ball.position.x - ball.direction.x,  ball.position.y - ball.direction.y };
	drawCircle(ball.position.x, ball.position.y, 10);

	return 0;
}