#include "GameScene.h"

GameScene::GameScene(std::unique_ptr<Game> oGame):mGame(std::move(oGame))
{

}


void GameScene::Init()
{
	mGame->Init(mGameController);
}

void GameScene::Update(uint32_t Dt)
{
	mGame->update(Dt);
}

void GameScene::Draw(Screen& theScreen)
{
	mGame->Draw(theScreen);
}

const std::string& GameScene::GetSceneName() const
{
	static std::string name = "";
	return name;
}