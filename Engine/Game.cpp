/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"


Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	b(Vec2(400.0f, 450.0f), Vec2(300.0f, 300.0f))
{
	int i = 0;
	for (int y = 0; y < rows; y++) 
	{
		const Color c = cls[y%4];
			for (int x = 0; x < cols; x++) 
			{
				bricks[i] = Brick(RectF(topleft + Vec2(float(x)*brickwidth, float(y)*brickheight), brickwidth, brickheight), c);
				i++;
			}
	}

}





void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_ESCAPE)) {
		exit(0);
	}
	const float dt = ft.Mark();
	b.Update(dt);

	pad.Update(wnd.kbd, dt);

	for (Brick& brk : bricks)
	{
		if (!brk.destroyed) {
			if (brk.DoBallCollision(b)) {
				if (b.GetRect().left < brk.brickrect.left) {
					b.ReboundX();
					brk.destroyed = true;
					break;
				}
				else if (b.GetRect().right > brk.brickrect.right) {
					b.ReboundX();
					brk.destroyed = true;
					break;
				}
				else {
					b.ReboundY();
					//b.SoundPlay(false, true);
					brk.destroyed = true;
					break;
				}

			}
		}
	}

	if (b.vel.y > 0.0f && pad.isColliding(b)) {
		if (b.GetRect().left < pad.GetRect().left) {
			b.ReboundX();
			//b.SoundPlay(true, false);
		}

		else if (b.GetRect().right > pad.GetRect().right) {
			b.ReboundX();
			//b.SoundPlay(true, false);
		}
		else {
				b.ReboundY();
				//b.SoundPlay(true, false);
			}
		}
	else {
		
	}
}


void Game::ComposeFrame()
{
	b.Draw(gfx);
	for (Brick& brk : bricks)
	{
		if (!brk.destroyed) {
			brk.Draw(gfx);
		}
	}
	pad.Draw(gfx);
}
