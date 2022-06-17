#pragma once
#include "Common.hpp"

class Paddle;

class SizePaddleBonus {
public:
	SizePaddleBonus() {};

	Clock getTimer() { return timer; };
	void restartTimer() { timer.restart(); };
	bool getActive() { return isActive; };
	void setActive(bool cond) { isActive = cond; };

	virtual void doBonus(Paddle& paddle);
	virtual void rollback(Paddle& paddle);
protected:
	bool isActive{ false };
	Clock timer;
};

class SpeedPaddleBonus : public SizePaddleBonus {
	void doBonus(Paddle& paddle);
	void rollback(Paddle& paddle);
};