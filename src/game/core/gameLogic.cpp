#include "gameLogic.h"
#include "forms.h"

void GameLogic::fallingLogic()
{
	auto& cells = Forms::getCellsActivities();  
	for (auto& cell : cells) 
	{
		cell.setYpos(cell.posYActiv + 1);  
	}
}