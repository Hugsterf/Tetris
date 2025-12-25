#include "game.h"
#include "core/forms.h"
#include "../logger/log.h"
#include "core/config.h"
#include "core/field.h"
#include "core/gameLogic.h"

static int i = 0;

Game::Game() : window(sf::VideoMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT), "Tetris")
{
    window.setFramerateLimit(60);

    for (size_t row = 0; row < Config::GRID_HEIGHT; row++)
    {
        for (size_t col = 0; col < Config::GRID_WIDTH; col++)
        {
            sf::RectangleShape shape(sf::Vector2f(Config::CELL_SIZE, Config::CELL_SIZE));
            int posX = (Field::getCell(row, col).getPosX());
            int posY = (Field::getCell(row, col).getPosY());

            shape.setPosition(posX, posY);
            addShape(shape);
        }
    }

    const std::vector<std::vector<int>> I = {
        {5, 6, 7, 0},
        {0, 6, 0, 0},
        {0, 6, 0, 0},
        {0, 6, 0, 0}
    };
    addShape(Forms::createShape(I, true));

    addShape(Forms::border());

    Forms::showActivCells();
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
        {
            window.close();
            LOG_ERROR("Окно закрыто!");
        } 
    }
}

void Game::update()
{
    i++;
    if (i >= 60)
    {
        GameLogic::fallingLogic();
        i = 0;
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
    LOG_TRACE("Добавление фигуры на позиции: X - " +
        std::to_string(shape.getPosition().x) +
        ", Y - " + std::to_string(shape.getPosition().y));
    shapes.push_back(shape);
}

void Game::addShape(const std::vector <sf::RectangleShape>& shapes)
{
    for (const auto& shape : shapes)
    {
        LOG_TRACE("Добавление фигуры на позиции: X - " +
            std::to_string(shape.getPosition().x) +
            ", Y - " + std::to_string(shape.getPosition().y));
        addShape(shape);
    }
}
