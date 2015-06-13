#pragma once
#include "ZeroRenderTargetManager.h"

class ZeroIShader : public ZeroIScene{
protected:
	bool m_bControl;
	char* m_iRenderPage;
	bool m_bRightErase;
public:
	ZeroIShader(char* renderpage);
	~ZeroIShader();

	void Update(float eTime);
	void Render();

	int IsControl()const{return m_bControl;}
	void SetControl(bool control){m_bControl = control;}

	bool IsRightErase()const{return m_bRightErase;}
	void SetRightErase(bool erase){m_bRightErase = erase;}
};