#ifndef APP_H
#define APP_H
#include "Screen.h"
#include "InputController.h"
#include <stdint.h>
#include <vector>
#include <memory>

struct SDL_Window;
class Scene;


class App
{

public:
	static App& Singleton();
	bool Init(uint32_t width, uint32_t height, uint32_t magnification);
	void Run();

	inline uint32_t Width() const { return mScreen.Width(); }
	inline uint32_t Height() const { return mScreen.Height(); }

	void PushScene(std::unique_ptr<Scene> scene);
	void PopScene();
	Scene* TopScene();

private:
	Screen mScreen;
	SDL_Window* noWindow;
	std::vector<std::unique_ptr<Scene>> mSceneStack;
	InputController mInputController;
};

#endif