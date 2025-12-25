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
    static void showActiv();

    static Cell getCell(int x, int y);
    static bool getActiv(int x, int y);

    static void changeActiv(int x, int y);
    static void setActiv(int x, int y, bool activ_);
};