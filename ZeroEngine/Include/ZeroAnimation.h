#pragma once
#include "ZeroSprite.h"
#include <vector>
#include <stdarg.h>

using namespace std;

class ZeroAnimation : public ZeroIScene{
private:
	float m_fFrame;
	float m_fFrameSpeed;
	int m_iMaxFrame;

	bool m_bStart;	//애니메이션 시작?정지?
	bool m_bLoop;	//애니메이션 루프
	vector<ZeroSprite*> m_Animates;
public:
	template <typename T>
	ZeroAnimation(T speed,bool loop=true){
		m_iMaxFrame = 0;
		m_fFrameSpeed = static_cast<float>(speed);
		m_fFrame = 0;
		m_bStart = true;
		m_bLoop = loop;
	}
	~ZeroAnimation();

	void PushSprite(char *path, ...);
	void Start();
	void Stop();

	template <typename T>
	void SetFrameSpeed(T speed){m_fFrameSpeed = static_cast<float>(speed);}

	template <typename T>
	void SetFrame(T frame){m_fFrame = static_cast<float>(frame);}
	float Frame()const{return m_fFrame;}

	int MaxFrame()const{return m_iMaxFrame;}

	void Update(float eTime);
	void Render();
};