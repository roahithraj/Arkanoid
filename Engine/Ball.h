#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "Vec2.h"
#include "SpriteCodex.h"


class Ball
{
public:
	Vec2 pos, vel;
	RectF ballrect;
	float radius = 7.0f;
public:
	Ball(Vec2& posin, Vec2& velin);
	void Draw(Graphics& gfx);
	void Update(float dt);
	void WallCollision();
	RectF GetRect() const;

	void ReboundY();
	void ReboundX();


};

