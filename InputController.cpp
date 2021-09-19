#include "InputController.h"
#include "GameController.h"
#include "SDL.h"


InputController::InputController():mQuit(nullptr), noCurrentController(nullptr)
{

}

void InputController::Init(InputAction quitAction)
{
	mQuit = quitAction;
}

void InputController::Update(uint32_t dt)
{
	SDL_Event sdlEvent;

	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
			case SDL_QUIT:
			{
				mQuit(dt, SDL_PRESSED);
			}
			break;
			case SDL_MOUSEMOTION:
			{
				if (noCurrentController)
				{
					if (MouseMovedAction mouseMoved = noCurrentController->GetMouseMovedAction())
					{
						MousePosition position;
						position.xPos = sdlEvent.motion.x;
						position.yPos = sdlEvent.motion.y;
						mouseMoved(position);
					}
				}
				break;
			}
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEBUTTONDOWN:
			{
				if (noCurrentController)
				{
					MouseInputAction action = noCurrentController->GetMouseButtonActionForMouseButton(static_cast<MouseButton>(sdlEvent.button.button));

					MousePosition position;
					position.xPos = sdlEvent.button.x;
					position.yPos = sdlEvent.button.y;

					action(static_cast<InputState>(sdlEvent.button.state), position);

				}
				break;
			}

			case SDL_KEYDOWN:
			case SDL_KEYUP:
			{
				if (noCurrentController)
				{
					InputAction action = noCurrentController->GetActionForKey(sdlEvent.key.keysym.sym);

					action(dt, static_cast<InputState>(sdlEvent.key.state));
				}
			}
			break;
			
		}
	}
}

void InputController::SetGameController(GameController* controller)
{
	noCurrentController = controller;
}