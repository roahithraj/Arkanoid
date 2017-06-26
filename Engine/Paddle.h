#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Ball.h"

class Paddle
{
public:
	Color c;
	Vec2 dimen;
	Vec2 pos;
	float vel;
	RectF paddlerect;
public:
	Paddle(const float velin);
	bool isColliding(Ball& ballin) const;
	void Draw(Graphics& gfx) const;
	void Update();
};

