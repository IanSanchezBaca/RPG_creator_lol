#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <vector>
#include <stdio.h>

class ColliderComponent;

class Game
{
public:
    Game();
    ~Game();

    void test_print();

    void initialize(const char *title,
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

    static std::vector<ColliderComponent *> colliders;

private:
    int test_counter = 0;
    bool isRunning;
    SDL_Window *window = NULL;
};

#endif