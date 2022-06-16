#include "Ball.hpp"

Ball::Ball(float x, float y, float radius, Color color) {
	shape.setPosition(x, y);
	shape.setRadius(radius);
	shape.setFillColor(color);
	shape.setOrigin(radius, radius);
}

bool Ball::update() {
	shape.move(velocity);
	//wall reflection
	if (left() < 0 || right() > windowWidth)
		velocity.x = -velocity.x;
	if (top() < 0)
		velocity.y = -velocity.y;
	else if (bot() > windowHeight) {
		velocity.y = -velocity.y;
		return false;
	}
	return true;
}