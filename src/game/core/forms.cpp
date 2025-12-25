#include "forms.h"
#include "../../logger/log.h"
#include "field.h"
#include <vector>

std::vector<Forms::Cell> Forms::cellsActivities;

//sf::RectangleShape Forms::Ibuild()
//{
//    sf::RectangleShape shape(sf::Vector2f(Config::CELL_SIZE, Config::CELL_SIZE));
//
//    int posX = (Field::getCell(0, Config::GRID_WIDTH / 2).getPosX());
//    int posY = (Field::getCell(0, 0).getPosY());
//
//    shape.setPosition(posX, posY);
//    shape.setFillColor(sf::Color::Red);
//
//    return shape;
//}

std::vector<sf::RectangleShape> Forms::createShape(const std::vector<std::vector<int>>& shapeTwoD, bool activ)
{
    std::vector <sf::RectangleShape> shapes;
    int k = 0;
    for (size_t i = 0; i < shapeTwoD.size(); i++)
    {
        for (size_t j = 0; j < shapeTwoD[i].size(); j++)
        {
            if (shapeTwoD[i][j] != 0)
            {
                sf::RectangleShape shape(sf::Vector2f(Config::CELL_SIZE, Config::CELL_SIZE));
                int posX = (Field::getCell(0, shapeTwoD[i][j] - 1).getPosX());
                int posY = (Field::getCell(k, 0).getPosY()); 

                Field::changeActiv(k, (shapeTwoD[i][j] - 1));
                addActiv(k, shapeTwoD[i][j] - 1);
                shape.setPosition(posX, posY);
                shape.setFillColor(sf::Color::Red);

                shapes.push_back(shape);
            }
        }
        k++;
    }
    return shapes;
}


sf::RectangleShape Forms::border()
{
    sf::RectangleShape border(sf::Vector2f(
        Config::GRID_TOTAL_WIDTH + 10,
        Config::GRID_TOTAL_HEIGHT + 10
    ));

    border.setPosition(
        Config::GRID_START_X - 5,
        Config::GRID_START_Y - 5
    );

    border.setFillColor(sf::Color::Transparent);
    border.setOutlineThickness(3);
    border.setOutlineColor(sf::Color::White);

    return border;
}

void Forms::showActivCells()
{
    for (const auto& cell : cellsActivities)
    {
        std::cout << "(" << cell.posXActiv << ", " << cell.posYActiv << "); ";
    }
}

std::vector<Forms::Cell>& Forms::getCellsActivities() {
    return cellsActivities;
}