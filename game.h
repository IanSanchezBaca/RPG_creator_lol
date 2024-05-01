/// game.h
/// This should take care of all the logic
/// Part of the newStart files
///
/// @author: Ian Sanchez Baca
/// @lastmodified: 04/24/24

#ifndef GAME_H
#define GAME_H
#define vect std::vector

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <vector>
#include <iostream>

/* my compiler is too old for regular filesystem library */
#include <experimental/filesystem>

class Game
{
public:
    Game();

    void test_print();

    void initialize(std::string title,
                    int xpos,
                    int ypos,
                    int width,
                    int height);

    void EventHandler();

    void update();

    void render();

    void close();

    bool running();

    // void loadMap();

    static SDL_Renderer *renderer;

    static SDL_Event event;

    void round();

private:
    // vect<vect<int>> grapha; // 25 x 20

    vect<std::string> tileName; // keeps track of what each tile is

    /* these are the coordinates of grapha on the graph */
    int x = -1;
    int y = -1;

    bool isRunning;

    int type = 1;

    int deleteMe = 0;

    bool rightClick = false;
    bool leftClick = false;

    SDL_Window *window = NULL;
};

#endif