#ifndef GAMES_H
#define GAMES_H
#include <string>
#include <stdint.h>

class GameController;
class Screen;

class Game
{

public:
	virtual ~Game() {}
	virtual void Init(GameController& controller) = 0;
	virtual void update(uint32_t dt) = 0;
	virtual void Draw(Screen& screen) = 0;
	virtual std::string GetName() const = 0;
};

#endif

