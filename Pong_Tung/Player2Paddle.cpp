#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Paddle player2;
extern Ball ball;
extern Ball ball2;
extern int Difficulty;
extern int LevelID;

int Player2Paddle1()
{
	bool canMove = true; //Ball1
	bool canMove2 = true; //Ball2
	float verticleDistance = 0;
	float horizontalDistance = 0;
	Vec2 chaseDirection = { 0, 0 };
	Vec2 player2Movement = { 0, 0 };

	//if the ball1 is in range and is closer than ball2
	if (ball.position.x >= 600 && ball.position.x < 1130 && ball2.position.x < ball.position.x)
	{
		//lets the paddle move when the ball is in range
		if (canMove == true)
		{
			if (Difficulty == 1) player2.speed = 4.5f;
			else if (Difficulty == 2) player2.speed = 6.3f;
			else if (Difficulty == 3) player2.speed = 8.0f;
			canMove = false;
		}

		horizontalDistance = ball.position.x - player2.position.x;
		verticleDistance = ball.position.y - player2.position.y;
		//chaseDirection.x = (player2.position.x + horizontalDistance) - player2.position.x;
		chaseDirection.y = (player2.position.y + verticleDistance) - player2.position.y;
		player2.position = { player2.position.x /*+ (chaseDirection.x * getDeltaTime() * player2.speed)*/,  player2.position.y + (chaseDirection.y * getDeltaTime() * player2.speed) };
	}

	//if the ball1 is in range and is closer than ball
	else if (ball2.position.x >= 600 && ball2.position.x < 1130 && ball.position.x < ball2.position.x && LevelID == 9)
	{
		//lets the paddle move when the ball2 is in range
		if (canMove2 == true)
		{
			if (Difficulty == 1) player2.speed = 4.5f;
			else if (Difficulty == 2) player2.speed = 6.3f;
			else if (Difficulty == 3) player2.speed = 8.0f;
			canMove2 = false;
		}

		horizontalDistance = ball2.position.x - player2.position.x;
		verticleDistance = ball2.position.y - player2.position.y;
		//chaseDirection.x = (player2.position.x + horizontalDistance) - player2.position.x;
		chaseDirection.y = (player2.position.y + verticleDistance) - player2.position.y;
		player2.position = { player2.position.x /*+ (chaseDirection.x * getDeltaTime() * player2.speed)*/,  player2.position.y + (chaseDirection.y * getDeltaTime() * player2.speed) };
	}

	DrawBox(player2.position, player2.height, player2.width);

	return 0;
}