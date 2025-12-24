#include "game.h"
#include "gameData.h"
#include "forms.h"

Game::Game() : window(sf::VideoMode(1000, 1000), "Tetris")
{
    window.setFramerateLimit(60);
    
    Forms::setSizeX(positionData::getSizeX());
}

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update()
{
    addShape(Forms::Ibuild());

    size_t sizeY = positionData::getSizeY();
    size_t sizeX = positionData::getSizeX();

    for (size_t row = 0; row < sizeY; row++)
    {
        int h = 25;

        for (size_t col = 0; col < sizeX; col++)
        {
            sf::RectangleShape shape(sf::Vector2f(25, h));
            int posX = positionData::getXPos(row, col);
            int posY = positionData::getYPos(row, col);

            shape.setPosition(posX + 2, posY + 2);
            addShape(shape);
        }
    }
}

void Game::render()
{
    window.clear(sf::Color::Black);

    for (const auto& shape : shapes)
    {
        window.draw(shape);
    }

    window.display();
}

void Game::addShape(const sf::RectangleShape& shape)
{
    shapes.push_back(shape);
}
