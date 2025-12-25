#pragma once
#include "cell.h"
#include "config.h"
#include <vector>

class Field
{
private:
	static std::vector<std::vector<Cell>> cells;

    Field() = delete;
public:
    static void initialize();

    static void show();

    static Cell getCell(int x, int j);
};