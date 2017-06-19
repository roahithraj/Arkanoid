#include "Ball.h"



Ball::Ball(Vec2& posin, Vec2& velin)
	:
	pos(posin),
	vel(velin)
{
}

void Ball::Draw(Graphics& gfx) {
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt) {
	pos += vel*dt;
}

void Ball::WallCollision() {

	const RectF ballrect = GetRect();

	if (ballrect.top < 0) {
		pos.y = radius + 1;
		ReboundY();
	}
	else if (ballrect.bottom >= Graphics::ScreenHeight) {
		pos.y = Graphics::ScreenHeight - radius - 1;
		ReboundY();
	}

	if (ballrect.left < 0) {
		pos.x = radius + 1;
		ReboundX();
	}
	else if (ballrect.right > Graphics::ScreenWidth) {
		pos.x = Graphics::ScreenWidth - radius - 1;
		ReboundX();
	}
}


void Ball::ReboundY() {
	vel.y = -vel.y;
}

void Ball::ReboundX() {
	vel.x = -vel.x;
}

RectF Ball::GetRect() const {

	RectF temprect;
	temprect.left = pos.x - radius;
	temprect.right = pos.x + radius;
	temprect.bottom = pos.y + radius;
	temprect.top = pos.y - radius;
	return temprect;
}
