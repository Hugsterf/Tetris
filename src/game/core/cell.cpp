#include "cell.h"
#include <iostream>

Cell::Cell() : 
    indexX(0), indexY(0), posX(0), posY(0),
    busy(false), activ(true), color(sf::Color::White)
{}

Cell::Cell(
    int indexX, int indexY, size_t x, size_t y,
    bool busy, bool activ, sf::Color color
)
    : posX(x), posY(y), busy(busy),
    indexX(indexX), indexY(indexY), activ(activ),
    color(color)
{}


void Cell::show() const
{
    std::cout << "(" << indexX << ", " << indexY << ") " << posX << " " << posY << "; ";
}

void Cell::showActiv() const
{
    std::cout << activ << "; ";
}