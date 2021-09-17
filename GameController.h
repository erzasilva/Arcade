#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "InputAction.h"
#include <vector>

class GameController
{
public:
	GameController();
	InputAction GetActionForKey(InputKey key);
	void AddInputActionForKey(const ButtonAction& buttonAction);
	void ClearAll();

	static bool IsPressed(InputState state);
	static bool IsReleased(InputState state);
	static InputKey ActionKey();
	static InputKey CancelKey();
	static InputKey LeftKey();
	static InputKey RightKey();
	static InputKey UpKey();
	static InputKey DownKey();

	inline const MouseMovedAction GetMouseMovedAction() { return mMouseMovedAction; }
	inline void SetMouseMovedAction(const MouseMovedAction& mouseMovedAction) { mMouseMovedAction = mouseMovedAction; }

	MouseInputAction GetMouseButtonActionForMouseButton(MouseButton button);



private:
	std::vector<ButtonAction> mButtonActions;
	MouseMovedAction mMouseMovedAction;
};

#endif