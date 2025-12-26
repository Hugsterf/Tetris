#pragma once
#include <string>

namespace Config 
{
    constexpr const char* TITLE = "Tetriis";

    constexpr int WINDOW_WIDTH = 1000;
    constexpr int WINDOW_HEIGHT = 1000;

    constexpr int GRID_WIDTH = 11;   
    constexpr int GRID_HEIGHT = 20;  
    constexpr int CELL_SIZE = 26;    
    constexpr int CELL_SPACING = 2; 

    constexpr int TOTAL_CELL_SIZE = CELL_SIZE + CELL_SPACING;
    constexpr int GRID_START_X = WINDOW_WIDTH / 3;
    constexpr int GRID_START_Y = WINDOW_HEIGHT / 4;

    constexpr int GRID_TOTAL_WIDTH = GRID_WIDTH * TOTAL_CELL_SIZE - CELL_SPACING;  
    constexpr int GRID_TOTAL_HEIGHT = GRID_HEIGHT * TOTAL_CELL_SIZE - CELL_SPACING;
}