#include "game/game.h"
#include "game/core/config.h"
#include "game/core/field.h"
#include "game/core/window.h"
#include "game/core/random.h"

int main()
{
    setlocale(LC_ALL, "");

    Field::initialize();
    Window::initializ();
    Rand::initialize();

    Game game;
    game.run();
}