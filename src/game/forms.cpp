#include "forms.h"

size_t Forms::sizeX = 0;

sf::RectangleShape Forms::Ibuild()
{
    sf::RectangleShape shape(sf::Vector2f(25, 25));

    size_t center = positionData::getSizeX() / 2; // test поменять

    int posX = positionData::getXPos(0, center);
    int posY = positionData::getYPos(0, center);

    shape.setPosition(posX, posY);
    shape.setFillColor(sf::Color::Red);

    return shape;
}