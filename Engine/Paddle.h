#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Ball.h"
#include "Keyboard.h"

class Paddle
{
public:
	Color c;
	Vec2 dimen;
	Vec2 pos;
	RectF paddlerect;
	float vel;
public:
	Paddle();
	bool isColliding(Ball& ballin) const;
	void Draw(Graphics& gfx);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect();
	void WallConfines();
};

