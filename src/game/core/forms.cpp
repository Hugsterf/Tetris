#include "forms.h"
#include "field.h"
#include <vector>

template<size_t row, size_t col>
void Forms::createShape(const int(&shape)[row][col], sf::Color color)
{
    int k = 0;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (shape[i][j] != 0)
            {
                Field::changeActiv(k, (shape[i][j] - 1));
                (Field::getCell(k, shape[i][j] - 1)).setColor(color);
            }
        }
        k++;
    }
}

template void Forms::createShape<4, 4>(const int(&)[4][4], sf::Color);
template void Forms::createShape<3, 3>(const int(&)[3][3], sf::Color);
template void Forms::createShape<2, 2>(const int(&)[2][2], sf::Color);