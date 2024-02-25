#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
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
    
    
    // SDL_Texture* playerTex;
    // used this to draw the image
    // SDL_Rect srcR, destR;
    // used this to resize and move image

    // no longer needed as they are being handled in another place
};

#endif