#include <iostream>
#include <SDL2/SDL.h> // The sdl library
#include <stdio.h>

// h files
// #include "main_menu.h"
#include "game.h"

using namespace std;

Game *game = NULL;

int main(int argc, char *args[])
{
    game = new Game();

    game->initialize("RPG Creator",
                     SDL_WINDOWPOS_CENTERED,
                     SDL_WINDOWPOS_CENTERED,
                     800,
                     600);

    while (game->running())
    {
        game->EventHandler();
        game->update();
        game->render();
    }

    game->close();

    return 0;
}