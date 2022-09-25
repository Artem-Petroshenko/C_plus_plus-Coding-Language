#pragma once

class Ball;

class Block;

class MovingBlock;

class Bonus {
public:
	Bonus() = default;
	//virtual ~Bonus() = default;

	Time getTime() { return timer.getElapsedTime(); };
	void restartTimer() { timer.restart(); };

	virtual void doBonus() {};
	virtual void rollback() {};
protected:
	Clock timer;
};

class MovingBlockBonus : public Bonus {
public:
	MovingBlockBonus(vector<Block>* _bricks, vector<MovingBlock>* _movingBricks) { bricks = _bricks;  movingBricks = _movingBricks; };
	//~SizePaddleBonus();

	void doBonus();

private:
	vector<Block>* bricks;
	vector<MovingBlock>* movingBricks;
};

class SecondBallBonus : public Bonus {
public:
	SecondBallBonus(vector<Ball>* _balls) { balls = _balls; };

	void doBonus();

private:
	vector<Ball>* balls;
};