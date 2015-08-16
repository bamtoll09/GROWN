/**
	@file ZeroFont.h
	*/

#pragma once

#include "ZeroIScene.h"
#include "ZeroResource.h"
#include <sstream>
#include <string>
#include <stdarg.h>

/**
	@class ZeroFont
	@brief 폰트 처리 담당 클래스
	*/
class ZeroFont : public ZeroIScene, public ZeroResource {
private:
	LPD3DXFONT font;
	std::string content;
	char* fontName;
	int fontSize;
	int fontWeight;

	void ReloadResource();

public:
	/**
		@brief ZeroFont의 생성자입니다.
		@param size 사용할 글꼴의 크기를 설정합니다.
		@param string 화면에 나타낼 문자열을 설정합니다.
		@param fontname 옵션. 사용할 글꼴을 나타냅니다. 기본값은 맑은 고딕입니다.
		사용하고자 하는 글꼴에서 속성 > 자세히에 나오는 제목을 넣으면 됩니다.
		@param filename 옵션. 글꼴의 경로를 나타냅니다.
		시스템에 설치하지 않은 글꼴을 사용할 때 사용합니다. 기본값은 NULL입니다.
		사용할 수 있는 글꼴의 종류는 fon, fnt, ttf, ttc, fot, otf, mmm, pfb, pfm입니다.
		*/
	ZeroFont(UINT _size, char* _string, char* _fontname = "맑은 고딕", char* _filename = NULL);
	~ZeroFont();

	void Render();
	void Update(float _eTime);

	/**
		@brief 화면에 나타낼 문자열을 설정합니다.
		@param string 화면에 나타낼 숫자입니다.
		*/

	void SetString(int _content);
	/**
		@brief 화면에 나타낼 문자열을 설정합니다.
		@param string 화면에 나타낼 문자입니다. printf() 함수처럼 가변 인자를 받습니다.
		*/
	void SetString(char* _format, ...);

	/**
		@brief 글꼴의 두께를 설정합니다.
		@param weight 글꼴의 두께입니다.
		*/
	void SetWeight(int _weight);

	/**
	@brief 현재 나타내고 있는 문자열을 반환합니다.
	*/
	const char* GetString() const;
};
