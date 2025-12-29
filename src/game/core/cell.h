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

    sf::Color color;

public:
    Cell();

    Cell(
        int indexX, int indexY, size_t x, size_t y,
        bool busy = false, bool activ = true, sf::Color = sf::Color::White
    );

    size_t getPosX() const { return posX; }
    size_t getPosY() const { return posY; }
    int getIndexX() const { return indexX; }
    int getIndexY() const { return indexY; }
    bool getActiv() const { return activ; }
    sf::Color getColor() const { return color; }

    bool isBusy() const { return busy; }
    bool isActiv() const { return activ; }

    void setPosX(size_t x) { posX = x; }
    void setPosY(size_t y) { posY = y; }
    void setIndexX(int indexX_) { indexX = indexX_; }
    void setIndexY(int indexY_) { indexY = indexY_; }
    void setPosition(size_t x, size_t y) { posX = x; posY = y; }
    void setBusy(bool busy_) { busy = busy_; }
    void setActiv(bool activ_) { activ = activ_; }
    void setColor(sf::Color color_) { color = color_; }

    void changeBusy() { busy = !busy; }
    void changeActiv() { activ = !activ; }

    void show() const;
    void showActiv() const;
};