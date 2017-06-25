#include "Ball.h"

Ball::Ball(Vec2& posin, Vec2& velin)
	:
	pos(posin),
	vel(velin),
	radius(7.0f),
	brickhit(L"Sounds\\arkbrick.wav"),
	paddlehit(L"Sounds\\arkpad.wav")
{
}

void Ball::Draw(Graphics& gfx) {
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt) {
	pos += vel*dt;
	WallCollision();
}

void Ball::WallCollision() {

	const RectF ballrect = GetRect();

	if (ballrect.top < 0) {
		pos.y = radius + 1;
		ReboundY();
		SoundPlay(true, false);

	}
	else if (ballrect.bottom >= Graphics::ScreenHeight) {
		pos.y = Graphics::ScreenHeight - radius - 1;
		ReboundY();
		SoundPlay(true, false);

	}

	if (ballrect.left < 0) {
		pos.x = radius + 1;
		ReboundX();
		SoundPlay(true, false);

	}
	else if (ballrect.right > Graphics::ScreenWidth) {
		pos.x = Graphics::ScreenWidth - radius - 1;
		ReboundX();
		SoundPlay(true, false);

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

void Ball::SoundPlay(bool bpaddlehit, bool bbrickhit) {

	bpaddlehit ? paddlehit.Play() : brickhit.Play();
}