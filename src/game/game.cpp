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
}

void Game::run()
{
    while (Window::isOpen())
    {
        Render::exitProgram();  
        Render::update();      
        Render::renderAll(); 
    }
}
