#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "Game.h"
#include <memory>

class GameScene : public Scene
{
public:
	GameScene(std::unique_ptr<Game> oGame);
	virtual ~GameScene() {}
	virtual void Init() override;
	virtual void Update(uint32_t Dt) override;
	virtual void Draw(Screen& theScreen) override;
	virtual const std::string& GetSceneName() const override;

private:
	std::unique_ptr<Game> mGame;
};


#endif