#include "EndScene.h"
#include "EndScene.h"
#include "TitleScene.h"


EndScene::EndScene()
{
	endButton = new Button("images/endButton.png", 300, 420);
	backgroundTitle = new Button("images/endSceneTitle.png", 200, 100);
	background = new CSprite("images/backgroundTest022.png");
	backgroundBack = new CSprite("images/bgTest.png");
	endGame = new Button("images/endGame.png",700, 420);
}


EndScene::~EndScene()
{
	delete endButton;
	delete background;
	delete backgroundBack;
	delete backgroundTitle;
	delete endGame;
}


void EndScene::Render()
{
	background->Render(0);
	backgroundBack->Render(0);
	endButton->Render(0);
	endGame->Render(0);
	backgroundTitle->Render(0);
}



void EndScene::Update(float eTime)
{
	endButton->Update(eTime);
	backGroundMove3(eTime);
	if (MyKeyState(VK_LBUTTON) == -1 &&
		endButton->CheckMouse())
	{
		ChangeScene(new TitleScene());
	}
	else if (MyKeyState(VK_LBUTTON) == -1 &&
		endGame->CheckMouse())
	{
		exit(0);
	}

}


void EndScene::backGroundMove3(float eTime)
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