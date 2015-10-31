#pragma once
#include "Zero.h"

class BlankSceneExit : public ZeroIScene {
private:
	float delay;

public:
	BlankSceneExit(float delay = 2.0f);
	~BlankSceneExit() override;

	virtual void Update(float eTime) override;
	virtual void Render() override;
};
