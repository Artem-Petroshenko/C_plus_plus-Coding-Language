#include "Ball.hpp"

float const ballRadius{ 10.f }; 
float ballSpeed{ 8.f };
extern int playerScore;

Ball::Ball(float x, float y) {
	shape = new CircleShape();
	shape->setPosition(x, y);
	shape->setRadius(ballRadius);
	shape->setFillColor(Color::White);
	shape->setOrigin(ballRadius, ballRadius);
}

Ball::Ball(const Ball& ball) {
	shape = new CircleShape(*ball.shape);
	speed = ball.speed;
}

Ball& Ball::operator=(const Ball& ball) {
	if (this == &ball)
		return *this;
	delete shape;
	shape = new CircleShape(*ball.shape);
	speed = ball.speed;
	return *this;
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