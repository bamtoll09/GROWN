#pragma once

#include <stdarg.h>
#include "ZeroIScene.h"
#include "ZeroResource.h"

class ZeroSprite : public ZeroIScene, public ZeroResource {
private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	string m_TexturePath;
	int m_iRenderState;

public:
	ZeroSprite(char *path, ...);
	~ZeroSprite();

	void Update(float eTime);
	void Render();

public:
	int RenderState() const {
		return m_iRenderState;
	}
	void SetRenderState(int renderstate) {
		m_iRenderState = renderstate;
	}

private:
	void ReloadResource();
};
