#include "Game.h"

#ifdef _DEBUG
int main()
#else
int WinMain()
#endif
{
    LLGP::Game game;
    game.run();
}