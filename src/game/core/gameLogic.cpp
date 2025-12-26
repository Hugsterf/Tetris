#include "gameLogic.h"
#include "field.h"

void GameLogic::fallLogic()
{
	for (size_t i = 0; i < Config::GRID_HEIGHT; i++)
	{
		for (size_t j = 0; j < Config::GRID_WIDTH; j++)
		{
			if (Field::getCell(i, j).getActiv() == true)
			{
				// доделать
			}
		}
	}
}