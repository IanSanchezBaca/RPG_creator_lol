/// game.h
/// This should take care of all the logic
/// Part of the newStart files
///
/// @author: Ian Sanchez Baca
/// @lastmodified: 04/24/24

#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <vector>
// #include <stdio.h>
#include <iostream>

using namespace std;

// class ColliderComponent;

class Game
{
public:
    Game();

    void test_print();

    void initialize(string title,
                    int xpos,
                    int ypos,
                    int width,
                    int height);

    void EventHandler();

    void update();

    void render();

    void close();

    bool running();

    static SDL_Renderer *renderer;

    static SDL_Event event;

    void round();

private:
    int x, y; // should be the position that the mouse clicked

    bool isRunning;

    SDL_Window *window = NULL;
};

#endif