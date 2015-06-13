#include "SoundExample.h"

/*--------------------------------------------------------------------------------*/
//
//							생성자 부분에서 변수 초기화
//
/*--------------------------------------------------------------------------------*/
SoundExample::SoundExample() {
	ZeroSoundMgr->PushSound(L"Sound/Example.wav", "sound1");
}
/*--------------------------------------------------------------------------------*/
//
//										소멸자
//
/*--------------------------------------------------------------------------------*/
SoundExample::~SoundExample() {
}
/*--------------------------------------------------------------------------------*/
//
//							Update 함수에서는 기능을 검사
//
/*--------------------------------------------------------------------------------*/
void SoundExample::Update(float eTime) {
	ZeroIScene::Update(eTime);

	//sound1 재생
	if (ZeroInputMgr->GetKey('Q') == INPUTMGR_KEYDOWN)
		ZeroSoundMgr->Play("sound1");

	//sound1 일시정지
	if (ZeroInputMgr->GetKey('W') == INPUTMGR_KEYDOWN)
		ZeroSoundMgr->Stop("sound1");

	//sound1 사운드 처음으로 되돌리기
	if (ZeroInputMgr->GetKey('E') == INPUTMGR_KEYDOWN)
		ZeroSoundMgr->Reset("sound1");
}
/*--------------------------------------------------------------------------------*/
//
//							Render함수에서는 그리기만 한다.
//
/*--------------------------------------------------------------------------------*/
void SoundExample::Render() {
	ZeroIScene::Render();
}