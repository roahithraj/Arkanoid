#include "Brick.h"
#include <assert.h>



Brick::Brick(RectF& rect, const Color cin)
	:
	brickrect(rect),
	c(cin)
{
}

void Brick::Draw(Graphics & gfx) const
{
		gfx.DrawRect(brickrect, c);
}

bool Brick::DoBallCollision(Ball& ball) {
	
	if (brickrect.isOverlapping(ball.GetRect())) {
		return true;
	}
	else
		return false;
}