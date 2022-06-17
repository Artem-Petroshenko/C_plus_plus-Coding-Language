#pragma once
#include "Common.hpp"

extern const float ballRadius;
extern float ballVelocity;

class Ball {
public:
	Ball(float x, float y, float radius, Color color);
	void update();

	//getters and setters
	CircleShape getShape() { return shape; };
	Vector2f getVelocity() { return velocity; };
	void setVelocity(float velX, float velY) { velocity.x = velX; velocity.y = velY; };

	//coordinates of a ball
	float x() { return shape.getPosition().x; };
	float y() { return shape.getPosition().y; };
	float left() { return x() - shape.getRadius(); };
	float right() { return x() + shape.getRadius(); };
	float top() { return y() - shape.getRadius(); };
	float bot() { return y() + shape.getRadius(); };

private:
	CircleShape shape;
	Vector2f velocity{ -ballVelocity, -ballVelocity };
};