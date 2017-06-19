#include "RectF.h"


RectF::RectF(float leftin, float topin, float rightin, float bottomin, Color cin)
	:
	left(leftin),
	top(topin),
	right(rightin),
	bottom(bottomin),
	c(cin)
{
}

//RectF::RectF(Vec2& topleft, Vec2& bottomright) {
//	RectF(topleft.x, topleft.y, bottomright.x, bottomright.y);
//}


//RectF::RectF(Vec2& topleft, float width, float height) {
//	RectF(topleft, Vec2(topleft.x + width, topleft.y + height));
//}
