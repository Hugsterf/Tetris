#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Game
{
private:
    sf::RenderWindow window;
    std::vector<sf::RectangleShape> shapes;

public:
    Game();
    void run();
    void addShape(const sf::RectangleShape& shape);
    void addShape(const std::vector <sf::RectangleShape>& shapes);
};