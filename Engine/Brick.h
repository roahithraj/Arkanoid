#pragma once
#include "RectF.h"
#include "Vec2.h"
#include "Graphics.h"

class Brick
{
public:
	RectF brickrect;
public:
	Brick() = default;
	Brick(RectF&);
	void Draw(Graphics& gfx) const;
};

