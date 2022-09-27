#pragma once
#include "Common.hpp"
#include "Bonus.hpp"
#include <assert.h>

extern float const paddleWidth, paddleHeight;
extern float paddleSpeed;
extern float const blockWidth, blockHeight;

class Block {
public:
	Block() = default;
	Block(float x, float y, float width, float height, Color color, bool breakability, bool boost, bool bonus);
	Block(const Block& block);
	Block& operator =(const Block& block);
	virtual ~Block() { delete shape; };

	float x() { return shape->getPosition().x; };
	float y() { return shape->getPosition().y; };
	float left() { return x() - shape->getSize().x / 2.f; };
	float right() { return x() + shape->getSize().x / 2.f; };
	float top() { return y() - shape->getSize().y / 2.f; };
	float bot() { return y() + shape->getSize().y / 2.f; };
	void setColor(Color _color) { shape->setFillColor(_color); };
	RectangleShape* getShape() { return shape; };
	bool isBreakable() { return breakable; };
	bool isBoosting() { return boosting; };
	bool haveBonus() { return withBonus; };
	int gethp() { return hp; };
	void sethp(int _hp) { hp = _hp; };

	virtual void update() {};

protected:
	RectangleShape* shape;
	bool breakable;
	int hp{ 1 };
	bool boosting;
	bool withBonus;
};

class MovingBlock : public Block {
public:
	MovingBlock(float x, float y, float width, float height, Color color, bool breakability, bool boost, bool bonus) : Block(x, y, width, height, color, breakability, boost, bonus) {};
	MovingBlock(const MovingBlock& block);
	MovingBlock& operator=(const MovingBlock& block);

	void setSpeedX(float _x) { speed.x = _x; };
	void setSpeedY(float _y) { speed.y = _y; };

	void update();

private:
	Vector2f speed{ -paddleSpeed, 0 };
};

class BonusBlock : public Block {
public:
	BonusBlock(float x, float y, float width, float height, Color color, bool breakability, bool boost, bool haveBonus) : Block(x, y, width, height, color, breakability, boost, haveBonus) {};
	BonusBlock(const BonusBlock& block);
	BonusBlock& operator=(const BonusBlock& block);
	~BonusBlock() = default;

	void update();

private:
	Vector2f speed{ 0, bonusSpeed };
};

class Paddle : public Block {
public:
	Paddle(float x, float y, float width, float height, Color color, bool breakability, bool boost, bool bonus) : Block(x, y, width, height, color, breakability, boost, bonus) {};
	Paddle(const Paddle& paddle);
	Paddle& operator=(const Paddle& paddle);

	void setSpeedX(float _x) { speed.x = _x; };
	void setSpeedY(float _y) { speed.y = _y; };

	void update();

private:
	Vector2f speed{ 0, 0 };
};