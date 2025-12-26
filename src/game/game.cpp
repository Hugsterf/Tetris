#include "game.h"
#include "core/forms.h"
#include "../logger/log.h"
#include "core/config.h"
#include "core/field.h"
#include "core/gameLogic.h"
#include "core/render.h"
#include "core/window.h"

static int i = 0;

Game::Game()
{
    const std::vector<std::vector<int>> I = {
        {5, 6, 7, 0},
        {0, 6, 0, 0},
        {0, 6, 0, 0},
        {0, 6, 0, 0}
    };
    Forms::createShape(I, true);

    /*addShape(Forms::border());*/
}

void Game::run()
{
    while (Window::isOpen())
    {
        Render::exitProgram();  
        Render::update();      
        Render::renderShapes(); 
    }
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
