#include "Brick.h"



Brick::Brick(RectF& rect)
	:
	brickrect(rect)
{
}

void Brick::Draw(Graphics & gfx) const
{
	gfx.DrawRect(brickrect);
}
