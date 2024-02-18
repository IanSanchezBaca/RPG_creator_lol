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
    const int FPS = 60;
    // will use this to limit fps? lol

    game = new Game();

    game->initialize("RPG Creator",
                     SDL_WINDOWPOS_CENTERED,
                     SDL_WINDOWPOS_CENTERED,
                     1280,
                     720);

    while (game->running())
    {
        game->EventHandler();
        game->update();
        game->render();
    }

    game->close();

    return 0;
}