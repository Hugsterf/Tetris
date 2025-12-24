#include "gameData.h"

int** positionData::posXMass = nullptr;
int** positionData::posYMass = nullptr;
size_t positionData::sizeX = 0;
size_t positionData::sizeY = 0;

void positionData::create(size_t sY, size_t sX)
{
    sizeY = sY;
    sizeX = sX;

    const int BLOCK_SIZE = 25;
    const int MARGIN = 5;
    const int TOTAL_SIZE = BLOCK_SIZE + MARGIN;
    const int MARGIN_X = 335;
    const int MARGIN_Y = 335;

    posXMass = new int* [sizeY];
    posYMass = new int* [sizeY];

    for (size_t i = 0; i < sizeY; i++)
    {
        posXMass[i] = new int[sizeX];
        posYMass[i] = new int[sizeX];
        for (size_t j = 0; j < sizeX; j++)
        {
            posYMass[i][j] = MARGIN_Y + (TOTAL_SIZE * i);
            posXMass[i][j] = MARGIN_X + (TOTAL_SIZE * j);
        }
    }
}

void positionData::destroy()
{
	if (posXMass)
	{
		for (size_t i = 0; i < sizeY; i++)
		{
			delete[] posXMass[i];
			delete[] posYMass[i];
		}
		delete[] posXMass;
		delete[] posYMass;

		posXMass = nullptr;
		posYMass = nullptr;
		sizeX = 0;
		sizeY = 0;
	}
}

void positionData::show() // deb
{
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t j = 0; j < sizeX; j++)
		{
			std::cout << posXMass[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t j = 0; j < sizeX; j++)
		{
			std::cout << posYMass[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int positionData::getXPos(size_t row, size_t col)
{
	if (posXMass && row < sizeY && col < sizeX)
	{
		return posXMass[row][col];
	}
	return 0;
}

int positionData::getYPos(size_t row, size_t col)
{
	if (posYMass && row < sizeY && col < sizeX)
	{
		return posYMass[row][col];
	}
	return 0;
}