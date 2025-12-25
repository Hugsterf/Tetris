#include "game/game.h"
#include "logger/log.h"
#include "game/core/config.h"
#include "game/core/field.h"

int main()
{
    setlocale(LC_ALL, "");
    Field::initialize();
    LOG_INFO("яНГДЮМХЕ АЮГШ ОНГХЖХИ: X - " + std::to_string(Config::GRID_WIDTH) + ", Y - " + std::to_string(Config::GRID_HEIGHT));
    Field::show();
    Game game;
    game.run();
}

// оепепюанрюрэ яхярелс онгхжхи тхцсп
// ядекюрэ дкъ йюфдни тхцспш ябни йкюяя / люо дкъ сверю онгхжхх тхцспш б опнярпюмярбе
// мюохяюрэ config.h дкъ namespace
// ндмю ъвеийю - 28 охйяекеи