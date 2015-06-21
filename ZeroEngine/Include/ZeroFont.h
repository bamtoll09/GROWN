#pragma once

#include "ZeroIScene.h"
#include "ZeroResource.h"
#include <stdarg.h>

class ZeroFont : public ZeroIScene, public ZeroResource {
private:
	LPD3DXFONT m_pFont;
	char* m_pString;
	char* m_pFontName;
	int m_FontSize;
	int m_iLen;

	void ReloadResource();

public:
	ZeroFont(UINT size, char* string, char* fontname = "맑은 고딕");
	~ZeroFont();

	void Render();
	void Update(float eTime);

	//void SetString(char* string);
	void SetString(int string);
	void SetString(char* string, ...);
};
