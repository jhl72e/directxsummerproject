#include "TitleScene.h"
#include "GameScene.h"

TitleScene::TitleScene()
{
	startButton = new Button("images/startButton.png", 430, 420);
	backgroundTitle = new Button("images/backgroundTitle.png", 230, 100);
	background = new CSprite("images/backgroundTest022.png");
	backgroundBack = new CSprite("images/bgTest.png");
}

TitleScene::~TitleScene()
{
	delete startButton;
	delete background;
	delete backgroundBack;
	delete backgroundTitle;
}

void TitleScene::Update(float eTime)
{
	startButton->Update(eTime);
	backGroundMove2(eTime);
	if (MyKeyState(VK_LBUTTON) == -1 &&
		startButton->CheckMouse())
	{
		ChangeScene(new GameScene());
	}

}

void TitleScene::Render()
{
	background->Render(0);
	backgroundBack->Render(0);
	startButton->Render(0);
	backgroundTitle->Render(0);
}


void TitleScene::backGroundMove2(float eTime)
{
	background->pos.y = 580;
	background->pos.x -= 700 * eTime;
	backgroundBack->pos.x -= 50 * eTime;
	if (background->pos.x <= -1280)
	{
		background->pos.x = 0;
	}
	if (backgroundBack->pos.x <= -1280)
	{
		backgroundBack->pos.x = 0;
	}


}