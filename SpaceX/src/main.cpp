#include "Game/Game.h"
#include "Gamestates/Menuestate.h"

int main()
{
    Game SpaceX;

    SpaceX.Run<Menuestate>();

    return 0;
}