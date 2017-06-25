#include "RectF.h"


RectF::RectF(float leftin, float topin, float rightin, float bottomin)
	:
	left(leftin),
	top(topin),
	right(rightin),
	bottom(bottomin)
{
}

RectF::RectF(Vec2& topleft, Vec2& bottomright) {
	RectF(topleft.x, topleft.y, bottomright.x, bottomright.y);
}


RectF::RectF(Vec2& topleft, float width, float height) {
	RectF(topleft, Vec2(topleft.x + width, topleft.y + height));
}

bool RectF::isOverlapping(const RectF& other) const{
	
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}