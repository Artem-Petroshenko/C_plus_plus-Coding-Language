#pragma once
#include "Common.hpp"

extern float const ballRadius;
extern float ballSpeed;

class Ball {
public:
	Ball(float x, float y);
	Ball(const Ball& ball);
	Ball& operator=(const Ball& ball);
	~Ball() { delete shape; };

	float x() { return shape->getPosition().x; };
	float y() { return shape->getPosition().y; };
	float left() { return x() - shape->getRadius(); };
	float right() { return x() + shape->getRadius(); };
	float top() { return y() - shape->getRadius(); };
	float bot() { return y() + shape->getRadius(); };
	CircleShape* getShape() { return shape; };
	void setSpeedX(float _x) { speed.x = _x; };
	void setSpeedY(float _y) { speed.y = _y; };

	void update();

private:
	CircleShape* shape;
	Vector2f speed{ -ballSpeed, -ballSpeed };
};