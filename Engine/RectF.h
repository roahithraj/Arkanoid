#pragma once
#include "Colors.h"
#include "Vec2.h"


class RectF
{
public:
	float left, top, right, bottom;
	public:
	RectF() = default;
	RectF(float leftin, float topin, float rightin, float bottomin);
	RectF(Vec2& topleft, Vec2& bottomright);
	RectF(Vec2& topleft, float width, float height);
	RectF GetExpanded(float offset) const;

	bool isOverlapping(const RectF& other) const;
};

