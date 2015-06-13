#pragma once
#include "ZeroIScene.h"

#define ZeroCameraMgr ZeroCameraManager::Instance()
class ZeroCameraManager{
private:
	ZeroVec m_vCameraPos;
	ZeroIScene* m_pTarget;

	bool m_bCamera;

	//카메라 영역
	int m_iWidth;
	int m_iHeight;

	//싱글 톤
	ZeroCameraManager();
public:
	~ZeroCameraManager();
	static ZeroCameraManager* Instance();
	
	void Update(float eTime);

	bool IsCamera()const{return m_bCamera;}
	void SetCameraOn(){m_bCamera = true;}
	void SetCameraOff(){m_bCamera = false;}
public:
	ZeroVec Pos()const{return m_vCameraPos;}
	void SetPos(ZeroVec pos){m_vCameraPos = pos;}
	template<typename T>
	void SetPos(T x,T y){m_vCameraPos.x = static_cast<float>(x); m_vCameraPos.y = static_cast<float>(y);}

	ZeroIScene* Target()const{return m_pTarget;}
	void SetTarget(ZeroIScene *target){m_pTarget = target;}

	int Width()const{return m_iWidth;}
	template<typename T>
	void SetWidth(T width){m_iWidth = static_cast<int>(width);}

	int Height()const{return m_iHeight;}
	template<typename T>
	void SetHeight(T height){m_iHeight = static_cast<int>(height);}

	template<typename T>
	void SetScreen(T width,T height){m_iWidth = static_cast<int>(width); m_iHeight = static_cast<int>(height);}
};