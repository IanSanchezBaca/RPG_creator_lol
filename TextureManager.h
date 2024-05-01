#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "game.h"

#define DEFAULT "media/background/test.png"
#define WATER "media/background/water.png"
#define GRASS "media/background/grass.png"
#define DIRT "media/background/dirt.png"

class TextureManager
{
public:
    static SDL_Texture *LoadTexture(const char *fileName);
    static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);

private:
    SDL_Rect src, dest;

    vect<SDL_Texture *> map;
};

#endif