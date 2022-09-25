#include "Ball.hpp"

float const ballRadius{ 10.f }; 
float ballSpeed{ 8.f };
extern int playerScore;

Ball::Ball(float x, float y) {
	shape->setPosition(x, y);
	shape->setRadius(ballRadius);
	shape->setFillColor(Color::White);
	shape->setOrigin(ballRadius, ballRadius);
}

void Ball::update() {
	shape->move(speed);
	
	if (left() < 0)
		speed.x = ballSpeed;
	else if(right() > windowWidth)
		speed.x = -ballSpeed;

	if (top() < 0)
		speed.y = ballSpeed;
	else if (bot() > windowHeight) {
		speed.y = -ballSpeed;
		playerScore--;
	}
}