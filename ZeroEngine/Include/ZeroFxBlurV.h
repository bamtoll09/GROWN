#pragma once

#include "ZeroIShader.h"

class ZeroFxBlurV : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;
	float m_fBlur;

public:
	ZeroFxBlurV(float time, char* renderpage);
	~ZeroFxBlurV();

	void Update(float eTime);
};
