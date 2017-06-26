#pragma once
#include "RectF.h"
#include "Vec2.h"
#include "Ball.h"
#include "Graphics.h"

class Brick
{
public:
	RectF brickrect;
	Color c;
	bool destroyed;

public:
	static constexpr float padding = 2.0f;
	Brick() = default;
	Brick(RectF& brickin, const Color cin);
	bool DoBallCollision(Ball& ball);
	void Draw(Graphics& gfx) const;
};

