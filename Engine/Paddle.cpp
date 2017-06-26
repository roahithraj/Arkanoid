#include "Paddle.h"

Paddle::Paddle(const float velin)
	:
	c(Colors::White),
	dimen(60.0f,20.0f),
	pos(370.0f,550.0f),
	vel(velin),
	paddlerect(pos, pos + dimen)
{

}

bool Paddle::isColliding(Ball& ballin) const {
	
	return paddlerect.isOverlapping(ballin.GetRect());
}

void Paddle::Draw(Graphics& gfx) const {
	gfx.DrawRect(paddlerect, c);
}