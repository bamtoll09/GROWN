#pragma once

#include <list>
#include "ZeroIEffect.h"
#include "ZeroIParticle.h"

class ZeroParticleSprite : public ZeroIEffect {
private:
	typedef std::list< ZeroIParticle* > PARTICLE;
	PARTICLE m_Particles;

	int m_StartA, m_StartR, m_StartG, m_StartB;
	int m_EndA, m_EndR, m_EndG, m_EndB;

	char* m_pPath;
	int m_iCount;
	int m_iSize;
	int m_iRenderState;
	float m_fTime;

	float m_fMinSpeed, m_fMaxSpeed;
	float m_fMinScale, m_fMaxScale;
	float m_fMinLifeTime, m_fMaxLifeTime;
	float m_fRotSpeed;
	float m_fDirection;
	float m_fSpread;

	void PushParticle(ZeroIParticle *p);
	void CreateParticle();

public:
	ZeroParticleSprite(char* path, int size = 1);
	~ZeroParticleSprite();

	void Start();

	void Update(float eTime);
	void Render();

	void SetParticleColorStart(int a, int r, int g, int b) {
		m_StartA = a, m_StartR = r, m_StartG = g, m_StartB = b;
	}
	
	void SetParticleColorEnd(int a, int r, int g, int b) {
		m_EndA = a, m_EndR = r, m_EndG = g, m_EndB = b;
	}
	
	template <typename T, typename U>
	void SetParticleSpeed(T minspeed, U maxspeed) {
		m_fMinSpeed = static_cast<float>(minspeed); m_fMaxSpeed = static_cast<float>(maxspeed);
	}
	
	template <typename T, typename U>
	void SetParticleScale(T minscale, U maxscale) {
		m_fMinScale = static_cast<float>(minscale); m_fMaxScale = static_cast<float>(maxscale);
	}
	
	template <typename T, typename U>
	void SetParticleLifeTime(T minlifetime, U maxlifetime) {
		m_fMinLifeTime = static_cast<float>(minlifetime); m_fMaxLifeTime = static_cast<float>(maxlifetime);
	}
	
	template <typename T>
	void SetParticleDirection(T direction) {
		m_fDirection = static_cast<float>(direction);
	}
	
	template <typename T>
	void SetParticleSpread(T spread) {
		m_fSpread = static_cast<float>(spread);
	}

	void SetRenderState(int renderstate) {
		m_iRenderState = renderstate;
	}
};
