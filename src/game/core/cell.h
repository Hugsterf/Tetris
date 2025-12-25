#pragma once
#include <SFML/Graphics.hpp>

class Cell 
{
private:
    // индексы в сетке
    int indexX;
    int indexY;

    // пиксели
    size_t posX;       
    size_t posY;   

    bool busy;     

public:
    Cell();

    Cell(int indexX, int indexY, size_t x, size_t y, bool busy = false);

    size_t getPosX() const { return posX; }
    size_t getPosY() const { return posY; }
    bool isBusy() const { return busy; }

    int getIndexX() const { return indexX; }
    int getIndexY() const { return indexY; }

    void setX(size_t x) { posX = x; }
    void setY(size_t y) { posY = y; }
    void setPosition(size_t x, size_t y) { posX = x; posY = y; }
    void setBusy(bool busy_) { busy = busy_; }

    void change() { busy = !busy; }

    void show() const;
};