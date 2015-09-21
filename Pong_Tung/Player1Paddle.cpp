#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

extern Paddle player1;

int Player1Paddle1()
{
	Vec2 player1Movement = { 0, 0 };

	//Apply movement and also limits how much the paddle can move
	if (getKey('w') && player1.position.y > 0 + player1.height/2) player1Movement.y = (1 * player1.speed) * getDeltaTime();
	if (getKey('s') && player1.position.y < 800 - player1.height / 2) player1Movement.y = (-1 * player1.speed) * getDeltaTime();

	player1.position = { player1.position.x - player1Movement.x,  player1.position.y - player1Movement.y };
	DrawBox(player1.position, player1.height, player1.width);

	return 0;
}