#pragma once
#include "IScene.h"
#include "Button.h"
#include "myFunction.h"
class EndScene :
	public IScene
{
public:

	Button *endButton;
	CSprite *background;
	Button *backgroundTitle;
	CSprite *backgroundBack;
	Button *endGame;

	EndScene();
	~EndScene();



	void backGroundMove3(float eTime);
	void Render();
	void Update(float eTime);
};
