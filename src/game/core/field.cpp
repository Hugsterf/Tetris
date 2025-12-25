#include "field.h"
#include <iostream>

std::vector<std::vector<Cell>> Field::cells;

void Field::initialize()
{
    cells.resize(Config::GRID_HEIGHT);
    for (size_t y = 0; y < Config::GRID_HEIGHT; y++)
    {
        cells[y].resize(Config::GRID_WIDTH);
        for (size_t x = 0; x < Config::GRID_WIDTH; x++)
        {
            int posX = (Config::WINDOW_WIDTH / 3) + x * (Config::CELL_SIZE + Config::CELL_SPACING);
            int posY = (Config::WINDOW_HEIGHT / 4) + y * (Config::CELL_SIZE + Config::CELL_SPACING);
            cells[y][x] = Cell(x, y, posX, posY, false, false);
        }
    }
}

void Field::show()
{
    for (size_t i = 0; i < Config::GRID_HEIGHT; i++)
    {
        for (size_t j = 0; j < Config::GRID_WIDTH; j++)
        {
            cells[i][j].show(); 
        }
        std::cout << std::endl;
    }
}

void Field::showActiv()
{
    for (size_t i = 0; i < Config::GRID_HEIGHT; i++)
    {
        for (size_t j = 0; j < Config::GRID_WIDTH; j++)
        {
            cells[i][j].showActiv();
        }
        std::cout << std::endl;
    }
}

Cell Field::getCell(int x, int y) 
{
    return cells[x][y];
}

void Field::changeActiv(int x, int y)
{
    cells[x][y].changeActiv();
}

void Field::setActiv(int x, int y, bool activ_)
{
    cells[x][y].setActiv(activ_);
}

bool Field::getActiv(int x, int y)
{
    return(cells[x][y].getActiv());
}