#include "gameLogic.h"
#include "field.h"
#include "random.h"
#include "render.h"

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
                    newCol < 0 || newCol >= Config::GRID_WIDTH) 
                {
                    return false;
                }
                auto& targetCell = Field::getCell(newRow, newCol);
                if (targetCell.isBusy() && !targetCell.getActiv())
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

int GameLogic::clearFullLines()
{
    int linesCleared = 0;
    std::vector<int> fullRows;

    for (int row = 0; row < Config::GRID_HEIGHT; row++)
    {
        bool full = true;
        for (int col = 0; col < Config::GRID_WIDTH; col++)
        {
            if (!Field::getCell(row, col).isBusy())
            {
                full = false;
                break;
            }
        }
        if (full) fullRows.push_back(row);
    }

    if (fullRows.empty()) return 0;

    linesCleared = fullRows.size();  

    std::sort(fullRows.begin(), fullRows.end());

    for (int i = fullRows.size() - 1; i >= 0; i--)
    {
        int rowToRemove = fullRows[i];

        for (int row = rowToRemove; row > 0; row--)
        {
            for (int col = 0; col < Config::GRID_WIDTH; col++)
            {
                auto& source = Field::getCell(row - 1, col);
                auto& dest = Field::getCell(row, col);

                dest.setBusy(source.isBusy());
                dest.setColor(source.getColor());
                dest.setActiv(false);

                source.setBusy(false);
                source.setActiv(false);
                source.setColor(sf::Color::White);
            }
        }

        for (int col = 0; col < Config::GRID_WIDTH; col++)
        {
            Field::getCell(0, col).setBusy(false);
            Field::getCell(0, col).setActiv(false);
            Field::getCell(0, col).setColor(sf::Color::White);
        }
    }

    return linesCleared;
}

void GameLogic::resetGame()
{
    for (int i = 0; i < Config::GRID_HEIGHT; i++)
    {
        for (int j = 0; j < Config::GRID_WIDTH; j++)
        {
            auto& cell = Field::getCell(i, j);
            
            cell.setActiv(false);
            cell.setBusy(false);
            cell.setColor(sf::Color::White);
        }
    }
}

void GameLogic::start()
{
    if (!GameLogic::fallLogic())
    {
        int cleared = GameLogic::clearFullLines();

        switch (cleared)
        {
        case 1:
            Render::addCount(40);
            break;
        case 2:
            Render::addCount(100);
            break;
        case 3:
            Render::addCount(300);
            break;
        case 4:
            Render::addCount(1200);
            break;
        default:
            break;
        }

        for (int i = 0; i < Config::GRID_WIDTH; i++)
        {
            auto& cell = Field::getCell(0, i);
            if (cell.isBusy())
            {
                GameLogic::resetGame();
            }
        }

        Rand::createRandomShape();
    }
}