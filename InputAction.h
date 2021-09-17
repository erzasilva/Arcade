#ifndef INPUTACTION_H
#define INPUTACTION_H

#include <functional>
#include <stdint.h>

/*
typedef uint8_t InputKey;
typedef uint8_t InputState;
typedef void (InputAction)(uint32_t, InputState);
*/

using InputKey = uint8_t;
using InputState = uint8_t;

using InputAction = std::function<void(uint32_t dt, InputState)>;

struct ButtonAction
{
	InputKey key;
	InputAction action;
};


#endif