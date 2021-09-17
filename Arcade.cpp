#include "Arcade.h"
#include "Line2D.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Screen.h"
#include "Color.h"
#include <iostream>

Arcade::Arcade()
{

}
void Arcade::Init()
{
	ButtonAction action;
	action.key = GameController::ActionKey();
	action.action = [](uint32_t dt, InputState state) {
		if (GameController::IsPressed(state))
		{
			std::cout << "ActionButton was pressed" << std::endl;
		}
	};
	mGameController.AddInputActionForKey(action);
	std::cout << action.key << std::endl;
}

void Arcade::Update(uint32_t Dt)
{

}

void Arcade::Draw(Screen& theScreen)
{
	Circle c = { Vec2D(theScreen.Width() / 2, theScreen.Height() / 2), 50 };
	Rectangle r = { Vec2D(60, 10), Vec2D(110, 110) };
	Triangle t = { Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110) };

	theScreen.Draw(c, Color::Magenta(), true, Color::Black());
	theScreen.Draw(r, Color::Yellow(), true, Color::Orange());
	theScreen.Draw(t, Color(0, 255, 0, 150), true, Color(0, 255, 0, 150));

}

const std::string& Arcade::GetSceneName() const
{
	static std::string sceneName = "Arcade App";
	return sceneName;
}

std::unique_ptr<Scene> Arcade::GetScene(eGame game)
{
	switch (game)
	{
		case TETRIS:
		{
		
		}
		break;

		case BREAKOUT:
		{

		}
		break;

		case ASTEROIDS:
		{

		}
		break;

		case PACMAN:
		{

		}
		break;

		case NUM_GAMES:
		{

		}
		break;
		default:
		{

		}
		break;

	}

	return nullptr;
}