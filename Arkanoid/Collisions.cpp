#include "Collisions.hpp"

template<class T1, class T2> bool isIntersacting(T1& a, T2& b) {
	return a.right() >= b.left() && a.left() <= b.right() && a.top() <= b.bot() && a.bot() >= b.top();
}

bool testCollision(Block& block, Ball& ball) {
	if (!isIntersacting(block, ball))
		return false;

	float coef = 1;

	if (block.getBreak()) {
		block.setHP(block.getHP() - 1);
		Color color = block.getShape().getFillColor();
		color.a = 85 * block.getHP();
		block.setColor(color);
	}

	//calculating the overlaps
	float overlapLeft(abs(ball.right() - block.left()));
	float overlapRight(abs(ball.left() - block.right()));
	float overlapTop(abs(ball.bot() - block.top()));
	float overlapBot(abs(ball.top() - block.bot()));

	//from where the ball hit the block
	bool ballFromLeft(overlapLeft < overlapRight);
	bool ballFromTop(overlapTop < overlapBot);

	//the ball hit the block horizontally or vertically
	float minOverLapX = ballFromLeft ? overlapLeft : overlapRight;
	float minOverLapY = ballFromTop ? overlapTop : overlapBot;

	if (minOverLapX < minOverLapY)
		ball.setVelocity(ballFromLeft ? -ballVelocity : ballVelocity, ball.getVelocity().y);
	else
		ball.setVelocity(ball.getVelocity().x, ballFromTop ? -ballVelocity : ballVelocity);
	if (block.getBoost()) {
		float coef = 1.5;
		ball.setVelocity(ball.getVelocity().x * coef, ball.getVelocity().y * coef);
	}
	return true;
}