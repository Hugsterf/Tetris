#include "game.h"
#include "core/forms.h"
#include "core/config.h"
#include "core/field.h"
#include "core/gameLogic.h"
#include "core/render.h"
#include "core/window.h"
#include "core/random.h"

Game::Game()
{
    Rand::createRandomShape();
}

void Game::run()
{   
    while (Window::isOpen())
    {
        Render::pollEvent();
        static int i;
        if (i >= 20)
        {
            GameLogic::start();
            i = 0;
        }
        i++;
        Render::update();
    }
}
