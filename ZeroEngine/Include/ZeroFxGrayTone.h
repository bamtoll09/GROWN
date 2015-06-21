#pragma once

#include "ZeroIShader.h"

class ZeroFxGrayTone : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

public:
	ZeroFxGrayTone(float time, char* renderpage);
	~ZeroFxGrayTone();

	void Update(float eTime);
};
