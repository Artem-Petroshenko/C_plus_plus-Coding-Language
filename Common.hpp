#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace sf;

int const windowWidth{ 800 }, windowHeight{ 600 };
int const blocksCountX{ 11 }, blocksCountY{ 4 };
float const bonusWidth{ 6.f }, bonusHeight{ 6.f }, bonusSpeed{ 6.f };