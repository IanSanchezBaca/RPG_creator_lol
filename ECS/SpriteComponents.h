#ifndef SPRITECOMPONENTS_H
#define SPRITECOMPONENTS_H

#include "../TextureManager.h"
#include "Components.h"
#include "SDL2/SDL.h"

class SpriteComponent : public Component{
    private:
        PositionComponent *position;
        SDL_Texture *texture;
        SDL_Rect srcRect, destRect;

    public: 
    SpriteComponent() = default;
    SpriteComponent(const char* path){

        setTex(path);

    }

    void setTex(const char* path){
        texture = TextureManager::LoadTexture(path);
    }
    
    void init() override{
        position = &entity->getComponent<PositionComponent>();
        
        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = 32;
        srcRect.h = 32;
        
        destRect.w = 64;
        destRect.h = 64;

    }// init

    void update() override{

        destRect.x = position->x();
        destRect.y = position->y();

    }// update

    void draw() override{

        TextureManager::Draw(texture, srcRect, destRect);

    }// draw
};



#endif