#include <SFML/Graphics.hpp>
#include <vector>
#pragma once

//здесь делаем отдельную функцию для каждой фигуры
//получаем размер Y поля для получения середины поля и размещения там фигры
//(если поле не делится без остатка - смещаем фигуру в правую сторону)
//каждая функция будет возвращать const sf::RectangleShape& shape чтобы в game.cpp сразу добавлять 
//через addShapes() (будет принимать массив)
//из positionData получаем позицию там где должна быть фигура

class Forms
{
private:
	Forms() = delete;
public:
	//static sf::RectangleShape Ibuild();

	static std::vector<sf::RectangleShape> createShape(const std::vector<std::vector<int>>& shapeTwoD);

	static sf::RectangleShape border();
};