#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include <string>
#include "SDL2/SDL.h"
#include "Components.h"

class ColliderComponent : public Component
{
private:
    /* data */
public:
    SDL_Rect collider;
    std::string tag;

    ColliderComponent(std::string t) { tag = t; }
    // ~ColliderComponent();

    TransformComponent *transform;

    void init() override
    {
        if (!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();

        Game::colliders.push_back(this);
    }

    void update() override
    {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);

        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }
};

#endif