#include <SFML/Graphics.hpp>
#include <vector>
#pragma once

class Forms
{
public:
	struct Cell
	{
		int posXActiv;
		int posYActiv;

		Cell(int x, int y) : posXActiv(x), posYActiv(y) {}

		void setXpos(int x) { posXActiv = x; }
		void setYpos(int y) { posYActiv = y; }
	};

private:
	static std::vector <Cell> cellsActivities;

	Forms() = delete;

public:
	static void addActiv(int x, int y)
	{
		cellsActivities.push_back(Cell(y, x));
	}

	static std::vector<sf::RectangleShape> createShape(const std::vector<std::vector<int>>& shapeTwoD, bool activ);

	static sf::RectangleShape border();

	static void showActivCells();

	static std::vector<Cell>& getCellsActivities();
};