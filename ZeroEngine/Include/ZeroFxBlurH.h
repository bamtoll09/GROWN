#pragma once
#include "ZeroIShader.h"

class ZeroFxBlurH : public ZeroIShader{
private:
	float m_fTime;
	float m_fBeginTime;

	float m_fBlur;
public:
	ZeroFxBlurH(float time,char* renderpage);
	~ZeroFxBlurH();

	void Update(float eTime);
};