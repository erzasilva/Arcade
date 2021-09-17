#include "App.h"
#include "SDL.h"
#include "Arcade.h"
#include <memory>
#include <iostream>
#include <cassert>


App& App::Singleton()
{
	static App theApp;
	return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t magnification)
{
	noWindow = mScreen.Init(width, height, magnification);
	std::unique_ptr<Arcade> arcadeScene = std::make_unique<Arcade>();
	PushScene(std::move(arcadeScene));
	return noWindow != nullptr;
}

void App::Run()
{
	if (noWindow)
	{
		/*
		theScreen.Draw(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, Color::Yellow());
		Line2D line = { Vec2D(0, 0), Vec2D(mScreen.Width(), mScreen.Height()) };
		mScreen.Draw(line, Color::White());
		*/

		
		mScreen.SwapScreen();

		bool running = true;

		uint32_t lastTick = SDL_GetTicks();
		uint32_t currentTick = lastTick;

		uint32_t dt = 10;
		uint32_t accumulator = 0;
		mInputController.Init([&running](uint32_t dt, InputState state) {
			running = false;
		});

		while (running)
		{
			currentTick = SDL_GetTicks();
			uint32_t frameTime = currentTick - lastTick;

			if (frameTime > 300)
			{
				frameTime = 300;
			}

			lastTick = currentTick;

			accumulator += frameTime;


			//Input
			mInputController.Update(dt);
			Scene* topScene = App::TopScene();
			assert(topScene && "No Scene in SceneStack");

			if (topScene)
			{
				//Update
				while (accumulator >= dt)
				{
					topScene->Update(dt);
					//update CurrentScene by dt
					//std::cout << "Delta Time Step = " << dt << std::endl;
					accumulator -= dt;
				}

				//Render
			
				topScene->Draw(mScreen);
			}

			mScreen.SwapScreen();
		}

	}


}

void App::PushScene(std::unique_ptr<Scene> scene)
{
	assert(scene && "Dont Push a Null Ptr");
	if (scene)
	{
		scene->Init();
		mInputController.SetGameController(scene->GetGameController());
		mSceneStack.emplace_back(std::move(scene));
		SDL_SetWindowTitle(noWindow, TopScene()->GetSceneName().c_str());
	}
}


void App::PopScene()
{
	if (mSceneStack.size() > 1)
	{
		mSceneStack.pop_back();
	}
	if (TopScene())
	{
		mInputController.SetGameController(TopScene()->GetGameController());
		SDL_SetWindowTitle(noWindow, TopScene()->GetSceneName().c_str());

	}
}

Scene* App::TopScene()
{
	if(mSceneStack.empty())
	{
		return nullptr;
	}
	else
	{
		return mSceneStack.back().get();
	}
}