#pragma once

#include "ZeroRenderTargetManager.h"

class ZeroIEffect : public ZeroIScene {
private:
	int m_iRenderPage;

public:
	ZeroIEffect();
	~ZeroIEffect();

	void Update(float eTime);
	void Render();

	int RenderPage() const {
		return m_iRenderPage;
	}
	void SetRenderPage(int renderpage) {
		m_iRenderPage = renderpage;
	}
};
