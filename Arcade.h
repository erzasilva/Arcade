#ifndef ARCADE_H
#define ARCADE_H
#include "Scene.h"
#include <memory>

enum eGame {
	TETRIS = 0,
	BREAKOUT,
	ASTEROIDS,
	PACMAN,
	NUM_GAMES
};

class Arcade :
    public Scene
{
public:
    Arcade();
	virtual void Init() override;
	virtual void Update(uint32_t Dt) override;
	virtual void Draw(Screen& theScreen) override;
	virtual const std::string& GetSceneName() const override;
private:
	std::unique_ptr<Scene> GetScene(eGame game);

};

#endif
