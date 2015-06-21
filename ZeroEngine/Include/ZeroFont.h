#pragma once

#include "ZeroIScene.h"
#include "ZeroResource.h"
#include <stdarg.h>

/**
	@class ZeroFont
	@brief 폰트 처리 담당 클래스
*/
class ZeroFont : public ZeroIScene, public ZeroResource {
private:
	LPD3DXFONT m_pFont;
	char* m_pString;
	char* m_pFontName;
	int m_FontSize;
	int m_iLen;
	int m_iWeight;

	void ReloadResource();

public:
	/**
		@brief ZeroFont의 생성자입니다.
		@param size 사용할 글꼴의 크기를 설정합니다.
		@param string 화면에 나타낼 문자열을 설정합니다.
		@param fontname 옵션. 사용할 글꼴을 나타냅니다. 기본값은 맑은 고딕입니다.
		@param filename 옵션. 글꼴의 경로를 나타냅니다. 시스템에 설치하지 않은 글꼴을 사용할 때 사용합니다. 기본값은 NULL입니다.
	*/
	ZeroFont(UINT size, char* string, char* fontname = "맑은 고딕", char *filename = NULL);
	~ZeroFont();

	void Render();
	void Update(float eTime);

	/**
		@brief 화면에 나타낼 문자열을 설정합니다.
		@param string 화면에 나타낼 숫자입니다.
	*/
	
	void SetString(int string);
	/**
		@brief 화면에 나타낼 문자열을 설정합니다.
		@param string 화면에 나타낼 문자입니다. printf() 함수처럼 가변 인자를 받습니다.
	*/
	void SetString(char* string, ...);

	/**
		@brief 글꼴의 두께를 설정합니다. 
		@param weight 글꼴의 두께입니다.
	*/
	void SetWeight(int weight);
};
