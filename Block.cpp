#include "Block.hpp"

const float paddleWidth{ 80.f }, paddleHeight{ 20.f };
const float blockWidth{ 60.f }, blockHeight{ 20.f };
const int countX{ 11 }, countY{ 4 };
float paddleVelocity{ 0.2f };

Block::Block(float x, float y, float width, float height, Color color, bool br, bool boo, bool bon) {
	shape.setPosition(x, y);
	shape.setSize({ width, height });
	shape.setFillColor(color);
	shape.setOrigin(width / 2.0, height / 2.0);
	breakable = br;
	boost = boo;
	withBonus = bon;
}

void Paddle::update() {
	shape.move(velocity);

	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)
		velocity.x = -paddleVelocity;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < windowWidth)
		velocity.x = paddleVelocity;
	else
		velocity.x = 0;
}

void BonusBlock::update() {
	shape.move(velocity);

	if (bot() > windowHeight)
		fell = true;
}