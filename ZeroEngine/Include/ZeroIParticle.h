#pragma once

#include <d3d9.h>
#include "ZeroIScene.h"
#include "ZeroResource.h"

class ZeroIParticle : public ZeroIScene, public ZeroResource {
private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	string m_TexturePath;

	ZeroVec m_vSpeed;
	float m_fLifeTime;
	float m_fNowLifeTime;
	float m_fRotSpeed;
	int m_iRenderState;

	int m_ColorA, m_ColorR, m_ColorG, m_ColorB;

	void ReloadResource();

public:
	ZeroIParticle(char *path, ZeroVec speed, float lifetime, float size, float rotspeed, int colorA, int colorR, int colorG, int colorB, int renderstate);
	~ZeroIParticle();

	void Render();
	void Update(float eTime);

	ZeroVec Speed() const {
		return m_vSpeed;
	}
	float LifeTime() const {
		return m_fLifeTime;
	}
	float NowLifeTime() const {
		return m_fNowLifeTime;
	}
	float RotSpeed() const {
		return m_fRotSpeed;
	}

	int RenderState() const {
		return m_iRenderState;
	}
	void SetRenderState(int renderstate) {
		m_iRenderState = renderstate;
	}

	void SetColorA(int a) {
		m_ColorA = a;
	}
	void SetColorR(int r) {
		m_ColorR = r;
	}
	void SetColorG(int g) {
		m_ColorG = g;
	}
	void SetColorB(int b) {
		m_ColorB = b;
	}
};
