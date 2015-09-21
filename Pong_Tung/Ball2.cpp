#include <iostream>
#include <cstring>
#include <ctime>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Ball ball2;
extern Paddle player1;
extern Paddle player2;
extern float previousDeltaTime;
extern Brick L2brickss[8];
extern Brick L3brickss[35];
extern Brick L3Movingbrickss[4];
extern int LevelID;

bool runOnceBall2 = true;
bool setStartingPosBall2 = true;
float outOfEdgetimerBall2 = 0;

int Ball2()
{
	srand(time(NULL));

	//Ball's starting direction of movement
	if (runOnceBall2 == true)
	{
		if (rand() % 2 == 0) ball2.direction = { -1 * (-1 * ball2.speed) * previousDeltaTime , 1 * (-1 * ball2.speed) * previousDeltaTime };
		else ball2.direction = { 1 * (-1 * ball2.speed) * previousDeltaTime , 1 * (-1 * ball2.speed) * previousDeltaTime };
		//previousDeltaTime = getDeltaTime();
		runOnceBall2 = false;
	}

	//Starting Positions for differnt levels
	if (setStartingPosBall2 == true)
	{
		ball2.position = { 780, 400 }; //Level 3
		setStartingPosBall2 = false;
	}

	//Reset the speed
	if (ball2.position.x < 0 - 300 || ball2.position.x > 1200 + 300)
	{
		outOfEdgetimerBall2 += getDeltaTime();
		if (outOfEdgetimerBall2 > 3.5)
		{
			if (rand() % 2 == 0) ball2.direction = { -1 * (-1 * ball2.speed) * previousDeltaTime , 1 * (-1 * ball2.speed) * previousDeltaTime };
			else ball2.direction = { 1 * (-1 * ball2.speed) * previousDeltaTime , 1 * (-1 * ball2.speed) * previousDeltaTime };
			outOfEdgetimerBall2 = 0;
		}
	}
	else
	{
		outOfEdgetimerBall2 = 0;
	}

	//Collisions//
	//////////////
	//When it hits a wall, reflect
	if (ball2.position.y < 20 || ball2.position.y > 780)
	{
		ball2.direction.y = -ball2.direction.y;
	}
	//if (ball.position.x < 20 || ball.position.x > 1180) ball.direction.x = -ball.direction.x;

	//When it hits the player1 paddle, reflect
	if (ball2.position.x - 10 <= player1.position.x + player1.width / 2  //right side
		&& ball2.position.x + 10 >= player1.position.x - player1.width / 2 //left side
		&& ball2.position.y >= player1.position.y - player1.height / 2 //top portion of left side side
		&& ball2.position.y <= player1.position.y + player1.height / 2) //bottom portion of left right side
	{
		if (ball2.position.y + 10 <= player1.position.y + player1.height / 2  //top side
			&& ball2.position.y + 10 >= player1.position.y - player1.height / 2 //bottom side
			&& ball2.position.x <= player1.position.x + player1.width / 2 - 0.3f //right
			&& ball2.position.x >= player1.position.x - player1.width / 2 + 0.3f) //left
		{
			ball2.direction.y = -ball2.direction.y * 1.05f;
		}

		ball2.direction.x = -ball2.direction.x * 1.05f;
	}

	//When it hits the player2 paddle, reflect
	if (ball2.position.x - 10 <= player2.position.x + player2.width / 2
		&& ball2.position.x + 10 >= player2.position.x - player2.width / 2
		&& ball2.position.y >= player2.position.y - player2.height / 2
		&& ball2.position.y <= player2.position.y + player2.height / 2)
	{
		if (ball2.position.y + 10 <= player2.position.y + player2.height / 2
			&& ball2.position.y + 10 >= player2.position.y - player2.height / 2
			&& ball2.position.x <= player2.position.x + player2.width / 2 - 0.3f
			&& ball2.position.x >= player2.position.x - player2.width / 2 + 0.3f)
		{
			ball2.direction.y = -ball2.direction.y * 1.05f;
		}

		ball2.direction.x = -ball2.direction.x * 1.05f;
	}

	//When it hits the bricks from level 3, reflect
	if (LevelID == 9)
	{
		for (int x = 0; x < 35; ++x)
		{
			if (ball2.position.x - 10 <= L3brickss[x].position.x + L3brickss[x].width / 2
				&& ball2.position.x + 10 >= L3brickss[x].position.x - L3brickss[x].width / 2
				&& ball2.position.y >= L3brickss[x].position.y - L3brickss[x].height / 2
				&& ball2.position.y <= L3brickss[x].position.y + L3brickss[x].height / 2)
			{
				if (ball2.position.y + 10 <= L3brickss[x].position.y + L3brickss[x].height / 2
					&& ball2.position.y + 10 >= L3brickss[x].position.y - L3brickss[x].height / 2
					&& ball2.position.x <= L3brickss[x].position.x + L3brickss[x].width / 2 - 0.3f
					&& ball2.position.x >= L3brickss[x].position.x - L3brickss[x].width / 2 + 0.3f)
				{
					ball2.direction.y = -ball2.direction.y;
				}

				ball2.direction.x = -ball2.direction.x;
				L3brickss[x].position.x = 9000;
			}
		}

		for (int x = 0; x < 4; ++x)
		{
			if (ball2.position.x - 10 <= L3Movingbrickss[x].position.x + L3Movingbrickss[x].width / 2
				&& ball2.position.x + 10 >= L3Movingbrickss[x].position.x - L3Movingbrickss[x].width / 2
				&& ball2.position.y >= L3Movingbrickss[x].position.y - L3Movingbrickss[x].height / 2
				&& ball2.position.y <= L3Movingbrickss[x].position.y + L3Movingbrickss[x].height / 2)
			{
				if (ball2.position.y + 10 <= L3Movingbrickss[x].position.y + L3Movingbrickss[x].height / 2
					&& ball2.position.y + 10 >= L3Movingbrickss[x].position.y - L3Movingbrickss[x].height / 2
					&& ball2.position.x <= L3Movingbrickss[x].position.x + L3Movingbrickss[x].width / 2 - 0.3f
					&& ball2.position.x >= L3Movingbrickss[x].position.x - L3Movingbrickss[x].width / 2 + 0.3f)
				{
					ball2.direction.y = -ball2.direction.y;
				}

				ball2.direction.x = -ball2.direction.x;
				L3Movingbrickss[x].position.x = 9000;
			}
		}
	}
	//////////////

	//Draw//
	ball2.position = { ball2.position.x - ball2.direction.x,  ball2.position.y - ball2.direction.y };
	drawCircle(ball2.position.x, ball2.position.y, 10);

	return 0;
}