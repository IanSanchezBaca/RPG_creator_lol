#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include <stdio.h>

class Game
{
    public:
    Game(); 
    ~Game();

    void test_print();

    void initialize(char *title,
                    int xpos,
                    int ypos,
                    int width,
                    int height);
    
    void EventHandler();

    void update();

    void render();

    void close();

    bool running();

    private:
    int test_counter = 0;
    bool isRunning;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
};

#endif