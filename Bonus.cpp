#include "Bonus.hpp"
#include "Block.hpp"

void SizePaddleBonus::doBonus(Paddle& paddle) {
	paddle.setPosition(paddle.getShape().getPosition().x, paddle.getShape().getPosition().y);
	float newWidth = paddle.getShape().getSize().x + 20.f;
	float newHeight = paddle.getShape().getSize().y;
	paddle.setSize(newWidth, newHeight);
	paddle.setOrigin(newWidth / 2.0, newHeight / 2.0);
}

void SizePaddleBonus::rollback(Paddle& paddle) {
	paddle.setPosition(paddle.getShape().getPosition().x, paddle.getShape().getPosition().y);
	float newWidth = paddle.getShape().getSize().x - 20.f;
	float newHeight = paddle.getShape().getSize().y;
	paddle.setSize(newWidth, newHeight);
	paddle.setOrigin(newWidth / 2.0, newHeight / 2.0);
}

void SpeedPaddleBonus::doBonus(Paddle& paddle) {
	paddleVelocity += 0.1f;
}

void SpeedPaddleBonus::rollback(Paddle& paddle) {
	paddleVelocity -= 0.1f;
}