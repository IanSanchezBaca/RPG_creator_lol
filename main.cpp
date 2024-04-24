#include <iostream>
#include <SDL2/SDL.h> // The sdl library
#include <stdio.h>

#include "game.h"

int main(/*int argc, char *args[]*/)
{
    // const int FPS = 60;
    // // will use this to limit fps? lol

    // const int frameDelay = 1000 / FPS;
    // Uint32 frameStart;
    // int frameTime;

    Game game;

    string name = "RPG Creator";

    game.initialize(name,
                    SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED,
                    800,  // width
                    640); // height

    while (game.running())
    {
        /* FIRST TAKE IN INPUT FROM THE USER */
        game.EventHandler();

        /* THEN UPDATE DEPENDING ON WHAT IS NEEDED */
        game.update();

        /* RENDER EVERYHTING TO THE SCREEN */
        game.render();
    }

    game.close();

    return 0;
}