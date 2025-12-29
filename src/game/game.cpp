#include "game.h"
#include "core/forms.h"
#include "../logger/log.h"
#include "core/config.h"
#include "core/field.h"
#include "core/gameLogic.h"
#include "core/render.h"
#include "core/window.h"

Game::Game()
{
    CREATE_SHAPE(O);
}

void Game::run()
{   
    while (Window::isOpen())
    {
        Render::pollEvent();
        Render::update();      
        Render::renderAll();
        static int i = 0;
        if (i++ >= 10)
        {
            GameLogic::start();
            i = 0;
        }
        i++;
        
    }
}
