/// main.cpp
/// Just runs an infinite loop of
/// * EventHandler
/// * update
/// * render
/// all while running() returns true
///
/// @author: Ian Sanchez Baca
/// @lastmodified: 04/24/24
#include <iostream>
#include <SDL2/SDL.h> // The sdl library
#include <stdio.h>
#include <csignal>

#include "game.h"

Game game; // putting this out here for reasons

void segfaultHandler(int signal);

int main(/*int argc, char *args[]*/)
{

    signal(SIGSEGV, segfaultHandler);

    std::string name = "RPG Creator";

    game.initialize(name,
                    SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED,
                    800,  // width
                    640); // height

    // /* testing the segfault lol */
    // int *ptr = nullptr;
    // *ptr = 42;

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

void segfaultHandler(int signal)
{
    (void)signal;

    std::cerr << "Woops! I segfaulted. Cleaning up before closing.\n";

    game.close();

    exit(EXIT_FAILURE); // Terminate the program
}