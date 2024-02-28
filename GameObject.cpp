#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
    // renderer = ren;
    objTexture = TextureManager::LoadTexture(textureSheet);

    xpos = x;
    ypos = y;
}

GameObject::~GameObject(){}

void GameObject::Update(){
    xpos++;
    ypos++;
    
    srcRect.h = 600;
    srcRect.w = 400;
    // these are the original dimensions of the image i am using in pixels

    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = 100;
    destRect.h = 100;
}

void GameObject::Render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}