#include "game/game.h"
#include "logger/log.h"
#include "game/core/config.h"
#include "game/core/field.h"
#include "game/core/window.h"
#include "game/core/random.h"

int main()
{
    setlocale(LC_ALL, "");

    Field::initialize();
    Window::initializ();
    Rand::initializ();

    LOG_INFO("Создание базы позиций: X - " + std::to_string(Config::GRID_WIDTH) + ", Y - " + std::to_string(Config::GRID_HEIGHT));
    Game game;
    Field::showActiv();
    game.run();
}

// сделать основные фигуры
// сделать рандом фигуры