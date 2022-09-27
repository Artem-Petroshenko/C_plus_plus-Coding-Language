#pragma once

class Ball;

class Block;

class MovingBlock;

class Bonus {
public:
	Bonus() = default;
	//Bonus(const Bonus& bonus) {};
	//Bonus(const SecondBallBonus& bonus) {};
	virtual ~Bonus() = default;

	virtual void doBonus() {};
	virtual void rollback() {};
};

class MovingBlockBonus : public Bonus {
public:
	MovingBlockBonus(vector<Block>* _bricks, vector<MovingBlock>* _movingBricks) { bricks = _bricks;  movingBricks = _movingBricks; };
	MovingBlockBonus(const MovingBlockBonus& bonus);
	MovingBlockBonus& operator=(const MovingBlockBonus& bonus);
	~MovingBlockBonus() {};

	void doBonus();

private:
	vector<Block>* bricks;
	vector<MovingBlock>* movingBricks;
};

class SecondBallBonus : public Bonus {
public:
	SecondBallBonus(vector<Ball>* _balls) { balls = _balls; };
	SecondBallBonus(const SecondBallBonus& bonus);
	SecondBallBonus& operator=(const SecondBallBonus& bonus);
	~SecondBallBonus() {};

	void doBonus();

private:
	vector<Ball>* balls;
};