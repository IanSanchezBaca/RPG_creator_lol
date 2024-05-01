#include "TextureManager.h"

SDL_Texture *TextureManager::LoadTexture(std::string texture)
{

    SDL_Surface *tempsurface = IMG_Load(texture.c_str());
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tempsurface);
    SDL_FreeSurface(tempsurface);

    return tex;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{

    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}