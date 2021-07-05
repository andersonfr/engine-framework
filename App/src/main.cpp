#include <sfml-engine/platform/entry_point.h>
#include <sfml-engine/game.h>
#include "appTestGame.h"

//runtimes
Game* CreateGame()
{
    return new AppTestGame("App Test Game");
}