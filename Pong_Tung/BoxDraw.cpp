#include <iostream>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;


void DrawBox(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width/2, Position.y + Height/2, Position.x + Width/2, Position.y + Height/2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x + Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y + Height / 2);
}