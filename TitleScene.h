#pragma once
#include "IScene.h"
#include "Button.h"
#include "myFunction.h"
class TitleScene :
	public IScene
{
public:
	Button *startButton;
	CSprite *background;
	Button *backgroundTitle;
	CSprite *backgroundBack;
	
	TitleScene();
	~TitleScene();

	void TitleScene::backGroundMove2(float eTime);
	void Render();
	void Update(float eTime);
};

