#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "game.h"

class TextureManager
{
public:
    static SDL_Texture *LoadTexture(const char *fileName, SDL_Renderer *ren);

private:
};

#endif