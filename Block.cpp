#include "Block.hpp"

float const paddleWidth{ 80.f }, paddleHeight{ 20.f };
float paddleSpeed{ 8.f };
float const blockWidth{ 60.f }, blockHeight{ 20.f };

Block::Block(float x, float y, float width, float height, Color color, bool breakability, bool boost, bool bonus) {
	shape->setPosition(x, y);
	shape->setSize({ width, height });
	shape->setFillColor(color);
	shape->setOrigin(width / 2.f, height / 2.f);
	breakable = breakability;
	boosting = boost;
	withBonus = bonus;
}

void MovingBlock::update() {
	shape->move(speed);

	if (left() < 0)
		speed.x = paddleSpeed;
	else if (right() > windowWidth)
		speed.x = -paddleSpeed;
}

void BonusBlock::update() {
	shape->move(speed);

	if (bot() > windowHeight)
		hp = 0;
}

void Paddle::update() {
	shape->move(speed);

	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)
		speed.x = -paddleSpeed;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < windowWidth)
		speed.x = paddleSpeed;
	else
		speed.x = 0;
}