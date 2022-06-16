#include "Block.hpp"

Block::Block(float x, float y, float width, float height, Color color, bool br, bool boo) {
	shape.setPosition(x, y);
	shape.setSize({ width, height });
	shape.setFillColor(color);
	shape.setOrigin(width / 2.0, height / 2.0);
	breakable = br;
	boost = boo;
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