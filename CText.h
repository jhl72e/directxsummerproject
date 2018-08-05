#pragma once
#include "IObject.h"
#include <string>
using namespace std;

class CText :
	public IObject
{
public:
	LPD3DXFONT pFont;
	string textString;
	bool isItalic;
	int size,weight;
	int opacity, red, green, blue;
	bool blendMode;
	RECT rect;

	CText();
	~CText();
	void SetSize(int size, int weight);
	void SetText(string str);
	void Update(float eTime);
	void Render(D3DXMATRIX* pmat);
};

