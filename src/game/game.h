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

private:
    void processEvents();
    void update();
    void render();
};