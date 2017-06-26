#include "Paddle.h"

Paddle::Paddle()
	:
	c(Colors::White),
	dimen(60.0f,20.0f),
	pos(70.0f,550.0f),
	paddlerect(pos, pos + dimen), 
	vel(300.0f)
{

}

bool Paddle::isColliding(Ball& ballin) const {
	
	return paddlerect.isOverlapping(ballin.GetRect());
}

void Paddle::Draw(Graphics& gfx)  {

	gfx.DrawRect(GetRect(), c);
}

void Paddle::Update(const Keyboard& kbd, float dt) {
	
	if (kbd.KeyIsPressed('A')) {

		pos.x -= vel*dt;
	}
	if (kbd.KeyIsPressed('D')) {

		pos.x += vel*dt;
	}
	WallConfines();
}

RectF Paddle::GetRect() {
	paddlerect.left = pos.x;
	paddlerect.right = paddlerect.left + dimen.x;
	return paddlerect;
}

void Paddle::WallConfines() {
	if (pos.x <= 0){
		pos.x = 1.0f;
	}

	else if (pos.x + dimen.x >= Graphics::ScreenWidth) {
		pos.x = Graphics::ScreenWidth - dimen.x -1;
	}
}