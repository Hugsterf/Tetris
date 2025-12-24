#include "gameData.h"

fieldData::fieldData(const size_t size) : size(size)
{
	mass = new int* [size];
	for (size_t i = 0; i < size; i++)
	{
		mass[i] = new int[size];
		for (size_t j = 0; j < size; j++)
		{
			mass[i][j] = 0;
		}
	}
}

void fieldData::show() const
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			std::cout << mass[i][j];
		}
		std::cout << std::endl;
	}
}

fieldData::~fieldData()
{
	for (size_t i = 0; i < size; i++)
	{
		delete[]mass[i];
	}
	delete[]mass;
}