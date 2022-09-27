#include "Block.hpp"
#include "Ball.hpp"

vector<Vector2f> xyEmpty;

void MovingBlockBonus::doBonus() {
	int i = rand() % xyEmpty.size();
	movingBricks->emplace_back(xyEmpty.at(i).x, xyEmpty.at(i).y, blockWidth, blockHeight, Color::Yellow, true, false, false);
}

MovingBlockBonus::MovingBlockBonus(const MovingBlockBonus& bonus) {
	bricks = bonus.bricks;
	movingBricks = bonus.movingBricks;
}

MovingBlockBonus& MovingBlockBonus::operator=(const MovingBlockBonus& bonus) {
	if (this == &bonus)
		return *this;
	bricks = bonus.bricks;
	movingBricks = bonus.movingBricks;
	return *this;
}

SecondBallBonus::SecondBallBonus(const SecondBallBonus& bonus) {
	balls = bonus.balls;
}

SecondBallBonus& SecondBallBonus::operator=(const SecondBallBonus& bonus) {
	if (this == &bonus)
		return *this;
	balls = bonus.balls;
	return *this;
}

void SecondBallBonus::doBonus() {
	balls->emplace_back(windowWidth / 2, windowHeight - 50 - paddleHeight / 2.f);
}

//SizePaddleBonus::~SizePaddleBonus() {
//	delete paddle; 
//}