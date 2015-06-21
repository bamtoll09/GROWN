#pragma once

#include <vector>
#include <stdarg.h>
#include "ZeroIScene.h"
#include "ZeroResource.h"

class ZeroLine : public ZeroIScene, public ZeroResource {
private:
	typedef std::vector<ZeroVec> POINTLIST;
	POINTLIST m_Points;

	LPD3DXLINE m_pLine;
	LPD3DXLINE m_pUtilLine;
	float m_LineWidth;
	DWORD m_LinePattern;

public:
	ZeroLine();
	~ZeroLine();

	//포인트들
	void PushFrontPoint(int num, ...);
	void PushBackPoint(int num, ...);
	void PushFrontPoint(ZeroVec point);
	void PushBackPoint(ZeroVec point);
	void PopFrontPoint(int numPop);
	void PopBackPoint(int numPop);
	void ClearPoint();

	//속성
	void SetLineWidth(float width);
	void SetLinePattern(DWORD pattern);

	//유틸리티 기능
	void DrawRect(ZeroRect rect);
	void DrawCircle(ZeroVec pos, float radius);

	void Update(float eTime);
	void Render();

private:
	void ReloadResource();
};
