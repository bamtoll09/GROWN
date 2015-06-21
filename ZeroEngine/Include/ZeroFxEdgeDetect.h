#pragma once

#include "ZeroIShader.h"

class ZeroFxEdgeDetect : public ZeroIShader {
private:
	float m_fTime;
	float m_fBeginTime;

public:
	ZeroFxEdgeDetect(float time, char* renderpage);
	~ZeroFxEdgeDetect();

	void Update(float eTime);
};
