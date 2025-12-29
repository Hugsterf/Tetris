#include "gameLogic.h"
#include "field.h"
#include "random.h"

bool GameLogic::testMove(int y, int x)
{
    for (int i = 0; i < Config::GRID_HEIGHT; i++)
    {
        for (int j = 0; j < Config::GRID_WIDTH; j++)
        {
            auto& cell = Field::getCell(i, j);
            if (cell.getActiv())
            {
                int newRow = i + y;
                int newCol = j + x;
                if (newRow < 0 || newRow >= Config::GRID_HEIGHT ||
                    newCol < 0 || newCol >= Config::GRID_WIDTH) // проверка границ
                {
                    return false;
                }
                auto& targetCell = Field::getCell(newRow, newCol);
                if (targetCell.isBusy() && !targetCell.getActiv()) // проверка клетки передвижения
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool GameLogic::fallLogic()
{
    if (!testMove(1, 0))  
    {
        for (int i = 0; i < Config::GRID_HEIGHT; i++)
        {
            for (int j = 0; j < Config::GRID_WIDTH; j++)
            {
                auto& cell = Field::getCell(i, j);
                if (cell.getActiv())
                {
                    cell.setActiv(false);
                    cell.setBusy(true);
                }
            }
        }
        return false;
    }
    for (int i = Config::GRID_HEIGHT - 2; i >= 0; i--)
    {
        for (int j = 0; j < Config::GRID_WIDTH; j++)
        {
            auto& cell = Field::getCell(i, j);
            if (cell.getActiv())
            {
                auto& cellBelow = Field::getCell(i + 1, j);

                cellBelow.setActiv(true);
                cellBelow.setColor(cell.getColor());
                cellBelow.setBusy(true); 

                cell.setActiv(false);
                cell.setBusy(false);
                cell.setColor(sf::Color::White);
            }
        }
    }

    return true;
}

void GameLogic::moveRight()
{
    if (!testMove(0, 1)) return; 
    for (int i = 0; i < Config::GRID_HEIGHT; i++)
    {
        for (int j = Config::GRID_WIDTH - 2; j >= 0; j--) 
        {
            auto& cell = Field::getCell(i, j);
            if (cell.getActiv())
            {
                auto& cellRight = Field::getCell(i, j + 1);

                cellRight.setActiv(true);
                cellRight.setColor(cell.getColor());
                cellRight.setBusy(cell.isBusy());

                cell.setActiv(false);
                cell.setColor(sf::Color::White);
                cell.setBusy(false);
            }
        }
    }
}

void GameLogic::moveLeft()
{
    if (!testMove(0, -1)) return;
    for (int i = 0; i < Config::GRID_HEIGHT; i++)
    {
        for (int j = 1; j < Config::GRID_WIDTH; j++) 
        {
            auto& cell = Field::getCell(i, j);
            if (cell.getActiv())
            {
                auto& cellLeft = Field::getCell(i, j - 1);
                cellLeft.setActiv(true);
                cellLeft.setColor(cell.getColor());
                cellLeft.setBusy(true); 

                cell.setActiv(false);
                cell.setColor(sf::Color::White);
                cell.setBusy(false);
            }
        }
    }
}

void GameLogic::start()
{
    if (!GameLogic::fallLogic())
    {
        Rand::createRandomShape();
    }
}