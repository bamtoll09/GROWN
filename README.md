ZeroEngine 예제 코드
=================

[ZeroEngine](https://github.com/zer0pen/ZeroEngine) 예제 코드입니다.

## 요구 사항
  - Visual Studio 2012 이상의 IDE

## 설치
  1. DirectX 9 SDK를 [다운로드](https://www.microsoft.com/en-us/download/confirmation.aspx?id=6812)받아 설치합니다. 기본 옵션으로 설치하시면 되고, 설치 후 나오는 `S1023` 오류는 무시해도 됩니다.
  2. `git clone https://github.com/zer0pen/ZeroEngine-Example.git` 명령 혹은 `Clone in Desktop`으로 이 Git 저장소를 복제합니다.
  3. ZeroEngine 라이브러리의 최신 버전을 [다운로드](https://github.com/zer0pen/ZeroEngine/releases)합니다.
  4. `ZeroEngine\Lib` 폴더에 라이브러리 파일을 붙여넣습니다.
  4. `ZeroEngine.sln` 파일을 열어 오류 없이 컴파일되는지 확인합니다.

## 설명
`WinMain.cpp` 파일에서 어떤 예제를 실행할 지 지정할 수 있습니다.
```C++
ZeroSceneMgr->ChangeScene(new SpriteExample());
```
사용 가능한 예제 목록:
  - `SpriteExample`
  - `InputManagerExample`
  - `LineExample`
  - `FontExample`
  - `FPSExample`
  - `MathManagerExample`
  - `SceneManagerExample`
  - `AnimationExample`
  - `ParticleExample`
  - `RenderTargetExample`
  - `ShaderExample`
  - `CameraExample`
  - `SoundExample`
