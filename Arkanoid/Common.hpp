#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace sf;

const int windowWidth{ 800 }, windowHeight{ 600 };
const float ballRadius{ 10.f }, ballVelocity{ 0.3f };
const float paddleWidth{ 80.f }, paddleHeight{ 20.f }, paddleVelocity{ 0.3f };
const float blockWidth{ 60.f }, blockHeight{ 20.f };
const int countX{ 11 }, countY{ 4 };