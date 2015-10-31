#pragma once
#include "Zero.h"

template <class T>
class BlankScene : public ZeroIScene {
private:
	float delay;
	float time;
	bool isChanged;

public:
	BlankScene(float time = 2.0f, float delay = 2.0f);
	~BlankScene() override;

	virtual void Update(float eTime) override;
	virtual void Render() override;
};

template <class T>
BlankScene<T>::BlankScene(float time, float delay)
:delay(delay), time(time), isChanged(false){}

template <class T>
BlankScene<T>::~BlankScene(){}

template <class T>
void BlankScene<T>::Update(float eTime){
	ZeroIScene::Update(eTime);
	if(!isChanged) {
		delay -= eTime;
		if (delay <= 0){
			ZeroSceneMgr->ChangeScene(new T, TR::Fade, time);
			isChanged = true;
		}
	}
}

template <class T>
void BlankScene<T>::Render(){
	ZeroIScene::Render();
	ZeroApp->GetDevice()->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255, 0, 0, 0), 1.0f, 0);
}