#include "cell.h"
#include <iostream>

Cell::Cell() : indexX(0), indexY(0), posX(0), posY(0), busy(false) {}

Cell::Cell(int indexX, int indexY, size_t x, size_t y, bool busy)
    : posX(x), posY(y), busy(busy), indexX(indexX), indexY(indexY) {}


void Cell::show() const
{
    std::cout << "(" << indexX << ", " << indexY << ") " << posX << " " << posY << "; ";
}