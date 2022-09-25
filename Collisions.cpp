#include "Collisions.hpp"

extern vector<Vector2f> xyEmpty;
extern float ballSpeed;
extern int playerScore;

template<class T1, class T2> bool isIntersecting(T1& a, T2& b) {
	return a.right() >= b.left() && a.left() <= b.right() && a.top() <= b.bot() && a.bot() >= b.top();
}

bool TestCollision(Block& block, Ball& ball) {
	if (!isIntersecting(block, ball))
		return false;

	if (block.isBreakable()) {
		block.sethp(block.gethp() - 1);
		Color color = block.getShape()->getFillColor();
		color.a = 85 * block.gethp();
		block.setColor(color);
		playerScore++;
	}

	if (block.isBoosting())
		ballSpeed += 0.01f;

	float overlapLeft{ abs(ball.right() - block.left()) };
	float overlapRight{ abs(block.right() - ball.left()) };
	float overlapTop{ abs(ball.bot() - block.top()) };
	float overlapBot{ abs(block.bot() - ball.top()) };

	bool ballFromLeft{ overlapLeft < overlapRight };
	bool ballFromTop{ overlapTop < overlapBot };

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBot };

	if (minOverlapX < minOverlapY)
		ball.setSpeedX(ballFromLeft ? -ballSpeed : ballSpeed);
	else
		ball.setSpeedY(ballFromTop ? -ballSpeed : ballSpeed);

	if (!block.gethp()) {
		xyEmpty.push_back({ block.getShape()->getPosition().x, block.getShape()->getPosition().y });
		if (block.haveBonus())
			return true;
	}		
	return false;
}

void TestCollisionBlock(MovingBlock& block1, Block& block2) { 
	if (!isIntersecting(block1, block2))
		return;

	float overlapLeft{ abs(block1.right() - block2.left()) };
	float overlapRight{ abs(block2.right() - block1.left()) };

	if (overlapLeft < overlapRight)
		block1.setSpeedX(-paddleSpeed);
	else
		block1.setSpeedX(paddleSpeed);
}

void TestCollisionBall(Ball& ball1, Ball& ball2) {
	if (!isIntersecting(ball1, ball2))
		return;

	float overlapLeft{ abs(ball1.right() - ball2.left()) };
	float overlapRight{ abs(ball2.right() - ball1.left()) };
	float overlapTop{ abs(ball1.bot() - ball2.top()) };
	float overlapBot{ abs(ball2.bot() - ball1.top()) };

	bool ballFromLeft{ overlapLeft < overlapRight };
	bool ballFromTop{ overlapTop < overlapBot };

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBot };

	if (minOverlapX < minOverlapY) {
		ball1.setSpeedX(ballFromLeft ? -ballSpeed : ballSpeed);
		ball2.setSpeedX(ballFromLeft ? ballSpeed : -ballSpeed);
	}
	else {
		ball1.setSpeedY(ballFromTop ? -ballSpeed : ballSpeed);
		ball2.setSpeedY(ballFromTop ? ballSpeed : -ballSpeed);
	}
}

bool TestCapture(Block& block, Paddle& paddle) {
	if (!isIntersecting(block, paddle))
		return false;

	block.sethp(0);
	return true;
}