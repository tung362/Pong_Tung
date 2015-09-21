#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "GameObjectStructures.h"
#include "GameObjectFunctions.h"

using namespace sfw;
using namespace std;

void DrawA(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x, Position.y - Height / 2, Position.x - Width / 2, Position.y + Height / 2);
	drawLine(Position.x, Position.y - Height / 2, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x - Width / 2, Position.y, Position.x + Width / 2, Position.y);
}

void DrawB(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x + Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y);
	drawLine(Position.x + Width / 2, Position.y, Position.x - Width / 2, Position.y);
	drawLine(Position.x + Width / 2, Position.y, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y + Height / 2);
}

void DrawC(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
}

void DrawD(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x, Position.y - Height / 2);
	drawLine(Position.x, Position.y - Height / 2, Position.x + Width / 2, Position.y);
	drawLine(Position.x + Width / 2, Position.y, Position.x, Position.y + Height / 2);
	drawLine(Position.x, Position.y + Height / 2, Position.x - Width / 2, Position.y + Height / 2);
}

void DrawE(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y, Position.x + Width / 2, Position.y);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
}

void DrawF(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y, Position.x, Position.y);
}

void DrawG(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y);
	drawLine(Position.x + Width / 2, Position.y, Position.x, Position.y);
}

void DrawH(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y, Position.x + Width / 2, Position.y);
}

void DrawI(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x, Position.y + Height / 2, Position.x, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
}

void DrawJ(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x, Position.y + Height / 2, Position.x, Position.y - Height / 2);
	drawLine(Position.x, Position.y + Height / 2, Position.x - Width / 2, Position.y + Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y);
}

void DrawK(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y, Position.x + Width / 2, Position.y + Height / 2);
}

void DrawL(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
}

void DrawM(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x, Position.y);
	drawLine(Position.x, Position.y, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);

}

void DrawN(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
}

void DrawO(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
}

void DrawP(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x, Position.y - Height / 2);
	drawLine(Position.x, Position.y - Height / 2, Position.x + Width / 2, Position.y - ((Height / 2) / 2));
	drawLine(Position.x + Width / 2, Position.y - ((Height / 2) / 2), Position.x, Position.y);
	drawLine(Position.x, Position.y, Position.x - Width / 2, Position.y);
}

void DrawQ(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - ((Width / 2) / 2), Position.y + ((Height / 2) / 2), Position.x + ((Width / 2) / 2), Position.y + ((Height / 2) + (Height / 2) / 2));
}

void DrawR(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x, Position.y - Height / 2);
	drawLine(Position.x, Position.y - Height / 2, Position.x + Width / 2, Position.y - ((Height / 2) / 2));
	drawLine(Position.x + Width / 2, Position.y - ((Height / 2) / 2), Position.x, Position.y);
	drawLine(Position.x, Position.y, Position.x - Width / 2, Position.y);
	drawLine(Position.x, Position.y, Position.x + Width / 2, Position.y + Height / 2);
}

void DrawS(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y);
	drawLine(Position.x - Width / 2, Position.y, Position.x + Width / 2, Position.y);
	drawLine(Position.x + Width / 2, Position.y, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
}

void DrawT(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x, Position.y + Height / 2, Position.x, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
}

void DrawU(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
}

void DrawV(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x, Position.y + Height / 2);
	drawLine(Position.x, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
}

void DrawW(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x + Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x, Position.y);
	drawLine(Position.x, Position.y, Position.x - Width / 2, Position.y + Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y + Height / 2);
}

void DrawX(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y + Height / 2);
}

void DrawY(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x, Position.y);
	drawLine(Position.x + Width / 2, Position.y - Height / 2, Position.x, Position.y);
	drawLine(Position.x, Position.y, Position.x, Position.y + Height / 2);
}

void DrawZ(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x + Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y + Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
}

void Draw1(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x, Position.y + Height / 2, Position.x, Position.y - Height / 2);
	drawLine(Position.x, Position.y - Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width /2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
}

void Draw2(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y);
	drawLine(Position.x + Width / 2, Position.y, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x + Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y);
}

void Draw3(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y, Position.x + Width / 2, Position.y);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
}

void Draw4(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x + Width / 2, Position.y, Position.x - Width / 2, Position.y);
	drawLine(Position.x - Width / 2, Position.y, Position.x - Width / 2, Position.y - Height / 2);
}

void Draw5(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x + Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y);
	drawLine(Position.x - Width / 2, Position.y, Position.x + Width / 2, Position.y);
	drawLine(Position.x + Width / 2, Position.y, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y + Height / 2);
}

void Draw6(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y);
	drawLine(Position.x + Width / 2, Position.y, Position.x - Width / 2, Position.y);
}

void Draw7(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x + Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y);
}

void Draw8(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x + Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y);
	drawLine(Position.x + Width / 2, Position.y, Position.x - Width / 2, Position.y);
	drawLine(Position.x + Width / 2, Position.y, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y + Height / 2);
}

void Draw9(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x + Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x - Width / 2, Position.y);
	drawLine(Position.x - Width / 2, Position.y, Position.x + Width / 2, Position.y);
}

void Draw0(Vec2 Position, float Height, float Width)
{
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x - Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y - Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y + Height / 2);
	drawLine(Position.x + Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
	drawLine(Position.x - Width / 2, Position.y + Height / 2, Position.x + Width / 2, Position.y - Height / 2);
}

void DrawText(Vec2 Position, const char Text[], float Height, float Width)
{
	for (int x = 0; x < strlen(Text); ++x)
	{
		if (Text[x] == 'A' || Text[x] == 'a') DrawA({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'B' || Text[x] == 'b') DrawB({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'C' || Text[x] == 'c') DrawC({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'D' || Text[x] == 'd') DrawD({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'E' || Text[x] == 'e') DrawE({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'F' || Text[x] == 'f') DrawF({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'G' || Text[x] == 'g') DrawG({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'H' || Text[x] == 'h') DrawH({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'I' || Text[x] == 'i') DrawI({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'J' || Text[x] == 'j') DrawJ({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'K' || Text[x] == 'k') DrawK({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'L' || Text[x] == 'l') DrawL({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'M' || Text[x] == 'm') DrawM({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'N' || Text[x] == 'n') DrawN({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'O' || Text[x] == 'o') DrawO({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'P' || Text[x] == 'p') DrawP({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'Q' || Text[x] == 'q') DrawQ({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'R' || Text[x] == 'r') DrawR({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'S' || Text[x] == 's') DrawS({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'T' || Text[x] == 't') DrawT({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'U' || Text[x] == 'u') DrawU({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'V' || Text[x] == 'v') DrawV({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'W' || Text[x] == 'w') DrawW({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'X' || Text[x] == 'x') DrawX({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'Y' || Text[x] == 'y') DrawY({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == 'Z' || Text[x] == 'z') DrawZ({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == '1') Draw1({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == '2') Draw2({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == '3') Draw3({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == '4') Draw4({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == '5') Draw5({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == '6') Draw6({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == '7') Draw7({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == '8') Draw8({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == '9') Draw9({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
		else if (Text[x] == '0') Draw0({ Position.x + (Width * x * 1.5f), Position.y }, Height, Width);
	}
}