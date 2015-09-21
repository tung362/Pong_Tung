#include <iostream>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Paddle player1;
extern Paddle player2;
extern Ball ball;
extern Ball ball2;
extern Text playerOneWinText;
extern Text playerTwoWinText;
extern int LevelID;
extern bool L2BrickRunOnce;
extern bool L3BrickRunOnce;

bool resetBall = false; //Ball1
bool resetBall2 = false; //Ball2
bool player1Won = false;
bool player2Won = false;
float timer = 0; //Ball1
float timer2 = 0; //Ball2
float gameResettimer = 0;

int BallResetAndScore1()
{
	if (player1Won == true || player2Won == true)
	{
		gameResettimer += getDeltaTime();

		//Reset everything
		if (gameResettimer > 3)
		{
			L2BrickRunOnce = true;
			L3BrickRunOnce = true;
			player1 = { true,{ 100, 400 }, 600, 0, 4, 100, 30 };
			player2 = { false,{ 1100, 400 }, 0, 0, 4, 100, 30 };

			//Change back to main menu
			LevelID = 2;

			player1Won = false;
			player2Won = false;
		}
	}

	//if player1 or player2 is not dead
	if (player1.lives > 0 && player2.lives > 0)
	{
		//Player2 score (Ball1)
		if (ball.position.x < 0)
		{
			timer += getDeltaTime();
			if (timer >= 4)
			{
				resetBall = true;
				player1.lives -= 1;
				timer = 0;
			}
		}
		//Player1 score (Ball1)
		else if (ball.position.x > 1200)
		{
			timer += getDeltaTime();
			if (timer >= 4)
			{
				resetBall = true;
				player2.lives -= 1;
				timer = 0;
			}
		}

		//Player2 score (Ball2)
		if (ball2.position.x < 0)
		{
			timer2 += getDeltaTime();
			if (timer2 >= 4)
			{
				resetBall2 = true;
				player1.lives -= 1;
				timer2 = 0;
			}
		}
		//Player1 score (Ball2)
		else if (ball2.position.x > 1200)
		{
			timer2 += getDeltaTime();
			if (timer2 >= 4)
			{
				resetBall2 = true;
				player2.lives -= 1;
				timer2 = 0;
			}
		}

		if (resetBall == true)
		{
			gameResettimer = 0;
			if (LevelID == 7) //Level 1
			{
				ball.position = { 600, 400 };
			}
			else if (LevelID == 8) //Level 2
			{
				ball.position = { 500, 400 };
			}
			else if (LevelID == 9) //Level 3
			{
				ball.position = { 400, 400 };
			}
			timer = 0;
			resetBall = false;
		}

		if (resetBall2 == true)
		{
			gameResettimer = 0;
			ball2.position = { 780, 400 };
			timer2 = 0;
			resetBall2 = false;
		}
	}
	else
	{
		if ((ball.position.x < 0 || ball.position.x > 1200) || (ball2.position.x < 0 || ball2.position.x > 1200))
		{
			if (player2.lives <= 0)
			{
				DrawText(playerOneWinText.position, playerOneWinText.text, playerOneWinText.Height, playerOneWinText.Width);
				player1Won = true;
			}
			else if (player1.lives <= 0)
			{
				DrawText(playerOneWinText.position, playerTwoWinText.text, playerOneWinText.Height, playerOneWinText.Width);
				player2Won = true;
			}
		}
	}

	return 0;
}