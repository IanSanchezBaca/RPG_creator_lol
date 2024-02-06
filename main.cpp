#include <iostream>
#include <SDL2/SDL.h> // The sdl library
#include <stdio.h>
#include "main_menu.h"
/* i forgot how to use .h files lol */

using namespace std;

bool main_init(SDL_Window *mw)
{
    // only initialize the window
    bool succ = true;

    // Initialized SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        succ = false;
    }
    else
    {
        // Create Window
        mw = SDL_CreateWindow("RPG Creator",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              640, // this is the width of the screen 
                              480, // this is the height of the screen
                              SDL_WINDOW_SHOWN);
        // the width and height are temporary until i figure out how tf all of this shid works

        if (mw == NULL)
        {
            cout << "Window could not be created! SDL_Error: " << SDL_GetError();
            succ = false;
        }
    }

    return succ;
}

int main(int argc, char *args[])
{
    /* Create window and initialize it */
    SDL_Window *main_window = NULL;
    main_init(main_window);

    SDL_Event e;
    bool quit = false;

    MainMenu main_menu;

    while (quit == false)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }

        }
    }

    SDL_DestroyWindow(main_window);

    SDL_Quit();

    return 0;
}