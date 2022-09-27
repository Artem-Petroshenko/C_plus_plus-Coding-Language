#include "Block.hpp"

float const paddleWidth{ 80.f }, paddleHeight{ 20.f };
float paddleSpeed{ 10.f };
float const blockWidth{ 60.f }, blockHeight{ 20.f };

Block::Block(float x, float y, float width, float height, Color color, bool breakability, bool boost, bool bonus) {
	shape = new RectangleShape();
	shape->setPosition(x, y);
	shape->setSize({ width, height });
	shape->setFillColor(color);
	shape->setOrigin(width / 2.f, height / 2.f);
	breakable = breakability;
	boosting = boost;
	withBonus = bonus;
}

Block::Block(const Block& block) {
	shape = new RectangleShape(*block.shape);
	hp = block.hp;
	breakable = block.breakable;
	boosting = block.boosting;
	withBonus = block.withBonus;
}

Block& Block::operator=(const Block& block) {
	if (this == &block)
		return *this;
	delete shape;
	shape = new RectangleShape(*block.shape);
	hp = block.hp;
	breakable = block.breakable;
	boosting = block.boosting;
	withBonus = block.withBonus;
	return *this;
}

//Block::Block(Block&& block) {
//	delete shape;
//	shape = block.getShape();
//	hp = block.hp;
//	breakable = block.breakable;
//	boosting = block.boosting;
//	withBonus = block.withBonus;
//}
//
//Block& Block::operator=(Block&& block) {
//	if (this == &block)
//		return *this;
//	delete shape;
//	shape = block.getShape();
//	hp = block.hp;
//	breakable = block.breakable;
//	boosting = block.boosting;
//	withBonus = block.withBonus;
//	return *this;
//}

MovingBlock::MovingBlock(const MovingBlock& block) {
	shape = new RectangleShape(*block.shape);
	hp = block.hp;
	breakable = block.breakable;
	boosting = block.boosting;
	withBonus = block.withBonus;
	speed = block.speed;
}

MovingBlock& MovingBlock::operator=(const MovingBlock& block) {
	if (this == &block)
		return *this;
	delete shape;
	shape = new RectangleShape(*block.shape);
	hp = block.hp;
	breakable = block.breakable;
	boosting = block.boosting;
	withBonus = block.withBonus;
	speed = block.speed;
	return *this;
}

void MovingBlock::update() {
	shape->move(speed);

	if (left() < 0)
		speed.x = paddleSpeed;
	else if (right() > windowWidth)
		speed.x = -paddleSpeed;
}

BonusBlock::BonusBlock(const BonusBlock& block) {
	shape = new RectangleShape(*block.shape);
	hp = block.hp;
	breakable = block.breakable;
	boosting = block.boosting;
	withBonus = block.withBonus;
	speed = block.speed;	
}

BonusBlock& BonusBlock::operator=(const BonusBlock& block) {
	if (this == &block)
		return *this;
	delete shape;
	shape = new RectangleShape(*block.shape);
	hp = block.hp;
	breakable = block.breakable;
	boosting = block.boosting;
	withBonus = block.withBonus;
	speed = block.speed;
	return *this;
}

void BonusBlock::update() {
	shape->move(speed);

	if (bot() > windowHeight)
		hp = 0;
}

Paddle::Paddle(const Paddle& paddle) {
	shape = new RectangleShape(*paddle.shape);
	hp = paddle.hp;
	breakable = paddle.breakable;
	boosting = paddle.boosting;
	withBonus = paddle.withBonus;
	speed = paddle.speed;
}

Paddle& Paddle::operator=(const Paddle& paddle) {
	if (this == &paddle)
		return *this;
	delete shape;
	shape = new RectangleShape(*paddle.shape);
	hp = paddle.hp;
	breakable = paddle.breakable;
	boosting = paddle.boosting;
	withBonus = paddle.withBonus;
	speed = paddle.speed;
	return *this;
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