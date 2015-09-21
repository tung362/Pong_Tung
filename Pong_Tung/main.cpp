#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;
//using std::cout

//1
int LevelID = 1; //0 = Exit, 1 = Splash Screen, 2 = Main Menu, 3 = Instruction, 4 = About, 5 = Level Select, 6 = Difficulty Select, 7 = Level1, 8 = Level2, 9 = Level3
int TempLevelID = 1; //Used for level select to determine the future level
int Difficulty = 1; //1 = easy, 2 = normal, 3 = hard;

//Objects
//Splashscreen
Text title = { { 300, 400 }, "Simple Pong", 50, 40 };

//Main Menu
Text mainTitle = { { 300, 100 }, "Simple Pong", 50, 40 };
Text playButton = { { 100, 300 }, "Play", 30, 20 };
Text instructionButton = { { 100, 400 }, "Instructions", 30, 20 };
Text aboutButton = { { 100, 500 }, "About", 30, 20 };
Text exitButton = { { 100, 600 }, "Exit", 30, 20 };
Box selectBox = { { 100, 300 }, 30, 250 };

//Insturction
Text instructTitle = { { 300, 100 }, "Instructions", 50, 40 };
Text wKeyText = { { 100, 300 }, "W   Move Up", 20, 10 };
Text sKeyText = { { 100, 400 }, "S   Move Down", 20, 10 };
Text instrucBackButton = { { 1040, 740 }, "Back", 30, 20 };

//About
Text tungText = { { 400, 400 }, "Tung Nguyen", 40, 30 };
Text aboutBackButton = { { 1040, 740 }, "Back", 30, 20 };

//Level Select
Text levelSelectTitle = { { 300, 100 }, "level Select", 50, 40 };
Text Level1Text = { { 300, 400 }, "Level 1", 40, 30 };
Text Level2Text = { { 300, 500 }, "Level 2", 40, 30 };
Text Level3Text = { { 300, 600 }, "Level 3", 40, 30 };
Text LSBackButton = { { 1040, 740 }, "Back", 30, 20 };

//Difficulty Select
Text difficultySelectTitle = { { 120, 100 }, "Difficulty Select", 50, 40 };
Text difEasy = { { 600, 300 }, "Easy", 20, 10 };
Text difNormal = { { 600, 400 }, "Normal", 20, 10 };
Text difHard = { { 600, 500 }, "Hard", 20, 10 };
Text DSBackButton = { { 1040, 740 }, "Back", 30, 20 };

//Levels (Every level)
Ball ball = { { 600, 400 },{ 0, 0 }, 15 };
Paddle player1 = { true, { 100, 400 }, 600, 0, 4, 100, 30 };
Paddle player2 = { false, { 1100, 400 }, 0, 0, 4, 100, 30 };
Text playerOneWinText = { { 450, 400 }, "Player 1 Wins", 25, 15 };
Text playerTwoWinText = { { 450, 400 }, "Player 2 Wins", 25, 15 };
Text playerOneLivesText = { { 30, 70 }, "Lives:", 20, 10 };
Text playerTwoLivesText = { { 1050, 70 }, "Lives:", 20, 10 };
Text playerOneLivesNumText = { { 130, 70 }, "0", 20, 10 };
Text playerTwoLivesNumText = { { 1150, 70 }, "0", 20, 10 };

//Level 2
Brick L2brickss[14];

//Level 3
Ball ball2 = { { 780, 400 },{ 0, 0 }, 15 };
Brick L3brickss[35];
Brick L3Movingbrickss[4];

int main()
{
	//Screen Size
	initContext(1200, 800, "Pong Tung");

	//OnLogicUpdate
	while (stepContext())
	{
		//Levels
		if (LevelID == 0)
		{
			termContext();
		}
		else if (LevelID == 1)
		{
			SplashScreen();
		}
		else if (LevelID == 2)
		{
			MainMenu();
		}
		else if (LevelID == 3)
		{
			Instructions();
		}
		else if (LevelID == 4)
		{
			About();
		}
		else if (LevelID == 5)
		{
			LevelSelect();
		}
		else if (LevelID == 6)
		{
			DifficultySelect();
		}
		else if (LevelID == 7)
		{
			BallResetAndScore1();
			LevelDisplay();
			Ball1();
			Player1Paddle1();
			Player2Paddle1();
		}
		else if (LevelID == 8)
		{
			BallResetAndScore1();
			LevelDisplay();
			Level2BrickMovement();
			Ball1();
			Player1Paddle1();
			Player2Paddle1();
		}
		else if (LevelID == 9)
		{
			BallResetAndScore1();
			LevelDisplay();
			Level3BrickMovement();
			Ball1();
			Ball2();
			Player1Paddle1();
			Player2Paddle1();
		}
	}

	termContext();
	return 0;
}