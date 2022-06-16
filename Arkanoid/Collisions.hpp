#pragma once
#include "Ball.hpp"
#include "Block.hpp"

template<class T1, class T2> bool isIntersacting(T1& a, T2& b);
bool testCollision(Block& block, Ball& ball);