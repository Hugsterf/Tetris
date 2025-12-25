#include "forms.h"
#include "../../logger/log.h"
#include "field.h"
#include <vector>

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

std::vector<sf::RectangleShape> Forms::createShape(const std::vector<std::vector<int>>& shapeTwoD)
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
                int posX = (Field::getCell(0, shapeTwoD[i][j] - 1).getPosX()); // -1 убираем проблемы индексов(0 - 1; 1 - 1)
                int posY = (Field::getCell(k, 0).getPosY()); 

                shape.setPosition(posX, posY);
                shape.setFillColor(sf::Color::Red);

                shapes.push_back(shape);
            }
        }
        k++;
    }
    return shapes;
}