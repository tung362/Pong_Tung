#pragma once

struct Vec2
{
	float x;
	float y;
};

struct Paddle
{
	bool isPlayerOne;
	Vec2 position;
	float speed;
	int score;
	int lives;
	float height;
	float width;
};

struct Brick
{
	Vec2 position;
	float speed;
	int health;
	float height;
	float width;
	bool MoveUp;
};

struct Ball
{
	Vec2 position;
	Vec2 direction;
	float speed;
};

struct Text
{
	Vec2 position;
	char text[128];
	float Height;
	float Width;
};

struct Box
{
	Vec2 position;
	float height;
	float width;
};