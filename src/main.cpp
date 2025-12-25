#include "game/game.h"
#include "logger/log.h"
#include "game/core/config.h"
#include "game/core/field.h"

int main()
{
    setlocale(LC_ALL, "");
    Field::initialize();
    LOG_INFO("Создание базы позиций: X - " + std::to_string(Config::GRID_WIDTH) + ", Y - " + std::to_string(Config::GRID_HEIGHT));
    Game game;
    Field::showActiv();
    game.run();
}

// доделать механику падания кубиков
// рендер принимает позиции кубиков, после редактирует у них эти же позиуции на координату по Y больше
// после отрисовывает