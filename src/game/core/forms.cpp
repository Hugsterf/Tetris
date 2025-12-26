#include "forms.h"
#include "../../logger/log.h"
#include "field.h"
#include <vector>

void Forms::createShape(const std::vector<std::vector<int>>& shapeTwoD, bool activ)
{
    std::vector <sf::RectangleShape> shapes;
    int k = 0;
    for (size_t i = 0; i < shapeTwoD.size(); i++)
    {
        for (size_t j = 0; j < shapeTwoD[i].size(); j++)
        {
            if (shapeTwoD[i][j] != 0)
            {
                Field::changeActiv(k, (shapeTwoD[i][j] - 1));
                (Field::getCell(k, shapeTwoD[i][j] - 1)).setColor(sf::Color::Red);
            }
        }
        k++;
    }
}

sf::RectangleShape Forms::border()
{
    sf::RectangleShape shape(sf::Vector2f(
        Config::GRID_TOTAL_WIDTH + 10,
        Config::GRID_TOTAL_HEIGHT + 10
    ));

    shape.setPosition(
        Config::GRID_START_X - 5,
        Config::GRID_START_Y - 5
    );

    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineThickness(3);
    shape.setOutlineColor(sf::Color::White);

    return shape;
}