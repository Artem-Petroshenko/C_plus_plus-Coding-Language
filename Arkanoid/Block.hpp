#pragma once
#include "Common.hpp"

class Block {
public:
	Block(float x, float y, const float width, const float height, Color color, bool br, bool boo);

	//getters and setters
	RectangleShape getShape() { return shape; };
	void setColor(Color color) { shape.setFillColor(color); };
	int getHP() { return hp; };
	void setHP(int newhp) { hp = newhp; };
	bool getBreak() { return breakable; };
	bool getBoost() { return boost; };

	//coordinates of a block
	float x() { return shape.getPosition().x; };
	float y() { return shape.getPosition().y; };
	float left() { return x() - shape.getSize().x / 2.0; };
	float right() { return x() + shape.getSize().x / 2.0; };
	float top() { return y() - shape.getSize().y / 2.0; };
	float bot() { return y() + shape.getSize().y / 2.0; };

protected:
	RectangleShape shape;
	int hp{ 3 };
	bool breakable;
	bool boost;
};

class Unbreakable : public Block {
public:
	Unbreakable(float x, float y, const float width, const float height, Color color, bool br, bool boo) : Block(x, y, width, height, color, br, boo) {};
};

class Paddle : public Block{
public:
	Paddle(float x, float y, const float width, const float height, Color color, bool br, bool boo) : Block(x, y, width, height, color, br, boo) {};
	void update();

	//getters and setters
	Vector2f getVelocity() { return velocity; };
	void setVelocity(float velX, float velY) { velocity.x = velX; velocity.y = velY; };

private:
	Vector2f velocity;
};
