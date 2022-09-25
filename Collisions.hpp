#pragma once
#include "Block.hpp"
#include "Ball.hpp"

template<class T1, class T2> bool isIntersecting(T1& a, T2& b);
bool TestCollision(Block& block, Ball& ball);
bool TestCapture(Block& block, Paddle& paddle);
void TestCollisionBlock(MovingBlock& block1, Block& block2);
void TestCollisionBall(Ball& ball1, Ball& ball2);