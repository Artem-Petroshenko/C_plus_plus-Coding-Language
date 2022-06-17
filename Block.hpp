#pragma once
#include "Bonus.hpp"

extern const float paddleWidth, paddleHeight;
extern const float blockWidth, blockHeight;
extern const int countX, countY;
extern float paddleVelocity;

class Block {
public:
	Block(float x, float y, const float width, const float height, Color color, bool br, bool boo, bool bon);

	//getters and setters
	RectangleShape getShape() { return shape; };
	void setSize(float width, float height) { shape.setSize({ width, height }); };
	void setPosition(float x, float y) { shape.setPosition(x, y); };
	void setOrigin(float x, float y) { shape.setOrigin(x, y); };
	void setColor(Color color) { shape.setFillColor(color); };
	int getHP() { return hp; };
	void setHP(int newhp) { hp = newhp; };
	bool getBreak() { return breakable; };
	bool getBoost() { return boost; };
	bool getWithBonus() { return withBonus; };

	//coordinates of a block
	float x() { return shape.getPosition().x; };
	float y() { return shape.getPosition().y; };
	float left() { return x() - shape.getSize().x / 2.0; };
	float right() { return x() + shape.getSize().x / 2.0; };
	float top() { return y() - shape.getSize().y / 2.0; };
	float bot() { return y() + shape.getSize().y / 2.0; };

protected:
	RectangleShape shape;
	int hp{ 1 };
	bool breakable;
	bool boost;
	bool withBonus;
};

class Unbreakable : public Block {
public:
	Unbreakable(float x, float y, const float width, const float height, Color color, bool br, bool boo, bool bon) : Block(x, y, width, height, color, br, boo, bon) {};
};

class Paddle : public Block {
public:
	Paddle(float x, float y, const float width, const float height, Color color, bool br, bool boo, bool bon) : Block(x, y, width, height, color, br, boo, bon) {};
	void update();

	//getters and setters
	Vector2f getVelocity() { return velocity; };
	void setVelocity(float velX, float velY) { velocity.x = velX; velocity.y = velY; };

private:
	Vector2f velocity;
};

class BonusBlock : public Block {
public:
	BonusBlock(float x, float y, const float width, const float height, Color color, bool br, bool boo, bool bon) : Block(x, y, width, height, color, br, boo, bon) {};
	void update();

	Vector2f getVelocity() { return velocity; };
	void setVelocity(float velX, float velY) { velocity.x = velX; velocity.y = velY; };
	SizePaddleBonus* getBonus() { return bonus; };
	void setBonus(SizePaddleBonus* _bonus) { bonus = _bonus; };
	void setBonusActive(bool cond) { bonus->setActive(cond); };
	void restartBonusTimer() { bonus->restartTimer(); };
	bool getFell() { return fell; };
	void setFell(bool cond) { fell = cond; };

private:
	Vector2f velocity;
	SizePaddleBonus* bonus;
	bool fell{ false };
};