#pragma once
#include "ZeroIScene.h"
#include "ZeroResource.h"
#include "ZeroMat.h"

class ZeroRenderTarget : public ZeroResource{
public:
	enum {
		BLENDING_NORMAL,
		BLENDING_LIGHTEN,
		BLENDING_DARKEN,
		BLENDING_MOREDARKEN,
	};
private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPDIRECT3DSURFACE9 m_pSurface;
	LPDIRECT3DSURFACE9 m_pOriginal;
	LPD3DXEFFECT m_pShader;
	string m_ShaderPath ;
	bool m_IsBegin ;

	ZeroRect m_Rect;
public:
	ZeroRenderTarget();
	~ZeroRenderTarget();

	void SetShader(char *path);
	void ClearShader();
	LPD3DXEFFECT Shader()const{return m_pShader;}
	LPDIRECT3DTEXTURE9 Texture()const{return m_pTexture;}

	void Render(D3DXMATRIX* mat = NULL);
	void Update(float eTime);
	void Begin(bool clear=true);
	void End();

	ZeroRect Rect()const{return m_Rect;}
	//본 객체의 테두리값을 반환한다.
	void SetRect(ZeroRect rect){m_Rect = rect;}
	//본 객체의 테두리 값을 설정한다.
	template<typename T,typename U,typename V,typename W>
	void SetRect(T left,U top,V right,W bottom){m_Rect.left = static_cast<LONG>(left); m_Rect.top = static_cast<LONG>(top); m_Rect.right = static_cast<LONG>(right); m_Rect.bottom = static_cast<LONG>(bottom);}
	//본 객체의 테두리값을 left, top, right, bottom 순으로 설정한다.

private:
	void OnPrevDeviceReset() ;
	void OnPostDeviceReset() ;
};