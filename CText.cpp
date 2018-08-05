#include "CText.h"
#include "myFunction.h"
extern LPDIRECT3DDEVICE9 g_pd3dDevice;
CText::CText() : IObject()
{
	size = 20;
	weight = 400;
	isItalic = false;
	D3DXCreateFont(g_pd3dDevice,
		size,	//height
		0,		//width
		weight,	//weight
		1,
		isItalic,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		"Arial",		//Arial 이나 System
		&pFont
	);
	D3DSURFACE_DESC desc;
	SetRect(&rect, pos.x, pos.y, 500, 500);

	opacity = red = green = blue = 255;
	blendMode = false;
}


CText::~CText()
{
	pFont->Release();
}

void CText::SetText(string str)
{
	textString = str;
}

void CText::SetSize(int size, int weight)
{
	this->size = size;
	this->weight = weight;
	D3DXCreateFont(g_pd3dDevice,
		size,	//height
		0,		//width
		weight,	//weight
		1,
		isItalic,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		"Arial",		//Arial 이나 System
		&pFont
	);
}

void CText::Update(float eTime)
{
	rect.left = pos.x;
	rect.top = pos.y;
	SetSize(size, weight);
}

void CText::Render(D3DXMATRIX* pmat)
{
	IObject::Render(pmat);
	pFont->DrawText(NULL,
		textString.c_str(),
		-1,
		&rect,
		DT_NOCLIP,
		D3DXCOLOR(red, green, blue, opacity)
	);
}