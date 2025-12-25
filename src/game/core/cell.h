#pragma once
#include <SFML/Graphics.hpp>

class Cell 
{
private:
    int indexX;
    int indexY;
    size_t posX;       
    size_t posY;   
    bool busy; 
    bool activ;

public:
    Cell();

    Cell(int indexX, int indexY, size_t x, size_t y, bool busy = false, bool activ = true);

    size_t getPosX() const { return posX; }
    size_t getPosY() const { return posY; }

    bool getActiv() const { return activ; }

    bool isBusy() const { return busy; }
    bool isActiv() const { return activ; }

    int getIndexX() const { return indexX; }
    int getIndexY() const { return indexY; }

    void setX(size_t x) { posX = x; }
    void setY(size_t y) { posY = y; }
    void setPosition(size_t x, size_t y) { posX = x; posY = y; }
    void setBusy(bool busy_) { busy = busy_; }
    void setActiv(bool activ_) { activ = activ_; }

    void changeBusy() { busy = !busy; }
    void changeActiv() { activ = !activ; }

    void show() const;
    void showActiv() const;
};