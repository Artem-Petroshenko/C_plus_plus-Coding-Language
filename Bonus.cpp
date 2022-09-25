#include "Block.hpp"
#include "Ball.hpp"

vector<Vector2f> xyEmpty;

void MovingBlockBonus::doBonus() {
	int i = rand() % xyEmpty.size();
	movingBricks->emplace_back(xyEmpty.at(i).x, xyEmpty.at(i).y, blockWidth, blockHeight, Color::Yellow, true, false, false);
}

void SecondBallBonus::doBonus() {
	balls->emplace_back(windowWidth / 2, windowHeight - 50 - paddleHeight / 2.f);
}

//SizePaddleBonus::~SizePaddleBonus() {
//	delete paddle; 
//}