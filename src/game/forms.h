#include <SFML/Graphics.hpp>
#include "gameData.h"
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
	static size_t sizeX; // размер поля по длине
public:
	static void setSizeX(size_t size) { sizeX = size; }

	static sf::RectangleShape Ibuild(); // палка 4 блока добавить параметры для куба
};