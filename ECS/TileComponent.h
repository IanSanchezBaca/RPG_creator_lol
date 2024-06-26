#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H
#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponents.h"
#include "SDL2/SDL.h"

class TileComponent : public Component
{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;

    SDL_Rect tileRect;
    int tileID;
    char *path;

    // std::string path;

    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id)
    {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = id;

        switch (tileID)
        {
        case 0:
            path = "media/background/water.png";
            break;
        case 1:
            path = "media/background/dirt.png";
            break;
        case 2:
            path = "media/background/grass.png";
            break;
        default:

            break;
        }
    }

    void init() override
    {
        entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, (float)tileRect.w, (float)tileRect.h, 1);

        transform = &entity->getComponent<TransformComponent>();

        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};

#endif