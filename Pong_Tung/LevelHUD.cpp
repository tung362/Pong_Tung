#include <iostream>
#include "sfwdraw.h"
#include <sstream>
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Paddle player1;
extern Paddle player2;
extern Text playerOneLivesText;
extern Text playerTwoLivesText;
extern Text playerOneLivesNumText;
extern Text playerTwoLivesNumText;

void LevelDisplay()
{
	//Convert Player 1 Score to String
	stringstream player1LivesToString;
	player1LivesToString << player1.lives;
	string P1str = player1LivesToString.str();

	//Convert Player 2 Score to String
	stringstream player2LivesToString;
	player2LivesToString << player2.lives;
	string P2str = player2LivesToString.str();

	
	DrawText(playerOneLivesText.position, playerOneLivesText.text, playerOneLivesText.Height, playerOneLivesText.Width);
	DrawText(playerTwoLivesText.position, playerTwoLivesText.text, playerTwoLivesText.Height, playerTwoLivesText.Width);
	DrawText(playerOneLivesNumText.position, P1str.c_str(), playerOneLivesNumText.Height, playerOneLivesNumText.Width);
	DrawText(playerTwoLivesNumText.position, P2str.c_str(), playerTwoLivesNumText.Height, playerTwoLivesNumText.Width);
}