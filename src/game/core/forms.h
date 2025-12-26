#include <SFML/Graphics.hpp>
#include <vector>
#pragma once

class Forms
{
private:
	Forms() = delete;

public:
	static void createShape(const std::vector<std::vector<int>>& shapeTwoD, bool activ);

	static sf::RectangleShape border();
};