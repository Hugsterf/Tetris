#include <SFML/Graphics.hpp>
#include <vector>
#include "shapes.h"
#pragma once

class Forms
{
private:
	Forms() = delete;

public:
    template<size_t row, size_t col>
    static void createShape(const int(&shape)[row][col], sf::Color color);
};